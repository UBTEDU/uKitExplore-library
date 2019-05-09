/******************************************************************************/
/*                             Start of crcmodel.c                            */
/******************************************************************************/
/*                                                                            */
/* Author : Ross Williams (ross@guest.adelaide.edu.au.).                      */
/* Date   : 3 June 1993.                                                      */
/* Status : Public domain.                                                    */
/*                                                                            */
/* Description : This is the implementation (.c) file for the reference       */
/* implementation of the Rocksoft^tm Model CRC Algorithm. For more            */
/* information on the Rocksoft^tm Model CRC Algorithm, see the document       */
/* titled "A Painless Guide to CRC Error Detection Algorithms" by Ross        */
/* Williams (ross@guest.adelaide.edu.au.). This document is likely to be in   */
/* "ftp.adelaide.edu.au/pub/rocksoft".                                        */
/*                                                                            */
/* Note: Rocksoft is a trademark of Rocksoft Pty Ltd, Adelaide, Australia.    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/* Implementation Notes                                                       */
/* --------------------                                                       */
/* To avoid inconsistencies, the specification of each function is not echoed */
/* here. See the header file for a description of these functions.            */
/* This package is light on checking because I want to keep it short and      */
/* simple and portable (i.e. it would be too messy to distribute my entire    */
/* C culture (e.g. assertions package) with this package.                     */
/*                                                                            */
/******************************************************************************/

#include "crc.h"

/******************************************************************************/

/* The following definitions make the code more readable. */

#define BITMASK(X) (1L << (X))
#define MASK32 0xFFFFFFFFL
#define LOCAL static

/******************************************************************************/

/* Returns the value v with the bottom b [0,32] bits reflected. */
/* Example: reflect(0x3e23L,3) == 0x3e26                        */
LOCAL ulong reflect(ulong v, int b)
{
	int   i;
	ulong t = v;
	for (i=0; i<b; i++)
	{
		if (t & 1L)
		{
			v|=  BITMASK((b-1)-i);
		}
		else
		{
			v&= ~BITMASK((b-1)-i);
		}

		t>>=1;
	}

	return v;
}

/******************************************************************************/
/* Returns a longword whose value is (2^p_cm->cm_width)-1.     */
/* The trick is to do this portably (e.g. without doing <<32). */
LOCAL ulong widmask(p_cm_t p_cm)
{
	return (((1L<<(p_cm->cm_width-1))-1L)<<1)|1L;
}

/******************************************************************************/

void cm_ini(p_cm_t p_cm)
{
	p_cm->cm_reg = p_cm->cm_init;
}

/******************************************************************************/

void cm_nxt (p_cm_t p_cm, int ch)
{
	int   i;
	ulong uch  = (ulong) ch;
	ulong topbit = BITMASK(p_cm->cm_width-1);

	if (p_cm->cm_refin)
	{
		uch = reflect(uch,8);
	}

	p_cm->cm_reg ^= (uch << (p_cm->cm_width-8));

	for (i=0; i<8; i++)
	{
		if (p_cm->cm_reg & topbit)
		{
			p_cm->cm_reg = (p_cm->cm_reg << 1) ^ p_cm->cm_poly;
		}
		else
		{
			p_cm->cm_reg <<= 1;
		}

		p_cm->cm_reg &= widmask(p_cm);
	}
}

/******************************************************************************/

void cm_blk (p_cm_t p_cm, p_ubyte_t blk_adr, ulong blk_len)
{
	while (blk_len--)
	{
		cm_nxt(p_cm,*blk_adr++);
	}
}

/******************************************************************************/

ulong cm_crc(p_cm_t p_cm)
{
	if (p_cm->cm_refot)
	{
		return p_cm->cm_xorot ^ reflect(p_cm->cm_reg,p_cm->cm_width);
	}
	else
	{
		return p_cm->cm_xorot ^ p_cm->cm_reg;
	}
}

/******************************************************************************/

ulong cm_tab(p_cm_t p_cm, int index)
{
	int   i;
	ulong r;
	ulong topbit = BITMASK(p_cm->cm_width-1);
	ulong inbyte = (ulong) index;

	if (p_cm->cm_refin)
	{
		inbyte = reflect(inbyte,8);
	}

	r = inbyte << (p_cm->cm_width-8);

	for (i=0; i<8; i++)
	{
		if (r & topbit)
		{
			r = (r << 1) ^ p_cm->cm_poly;
		}
		else
		{
			r<<=1;
		}
	}

	if (p_cm->cm_refin)
	{
		r = reflect(r, p_cm->cm_width);
	}

	return r & widmask(p_cm);
}

/******************************************************************************/
/*                            hewei add function                              */
/******************************************************************************/
//crc8-itu
unsigned char crc8(unsigned char* buf, unsigned char len)
{
	//Step 1
	cm_t cm;

	//Step 2
	cm.cm_width = 8;
	cm.cm_poly  = 0x07L; 
	cm.cm_init  = 0x00L;
	cm.cm_refin = FALSE;
	cm.cm_refot = FALSE;
	cm.cm_xorot = 0x55L; 

	//Step 3
	cm_ini(&cm);

	//Step 4
	cm_blk(&cm, buf, len);
	//or 1 by 1
	/*
	for(int i=0; i<sizeofarray(check); i++){
		cm_nxt(&cm, check[i]);
	}
	*/

	//Step 5
	return cm_crc(&cm);
}

//crc16-MODBUS
unsigned short crc16(unsigned char* buf, unsigned char len)
{
	//Step 1
	cm_t cm;

	//Step 2
	cm.cm_width = 16;
	cm.cm_poly  = 0x8005L; 
	cm.cm_init  = 0xFFFFL;
	cm.cm_refin = TRUE;
	cm.cm_refot = TRUE;
	cm.cm_xorot = 0x0000L; 

	//Step 3
	cm_ini(&cm);

	//Step 4
	cm_blk(&cm, buf, len);

	//Step 5
	return cm_crc(&cm);
}

//数据较大，需要分包进行crc32校验的情况
void crc32_pack_init(p_cm_t cm)
{
//	//Step 1
//	cm_t cm;

	//Step 2
	cm->cm_width = 32;
	cm->cm_poly  = 0x04C11DB7L; 
	cm->cm_init  = 0xFFFFFFFFL;
	cm->cm_refin = TRUE;
	cm->cm_refot = TRUE;
	cm->cm_xorot = 0xFFFFFFFFL; 

	//Step 3
	cm_ini(cm);
}

void crc32_pack(p_cm_t cm, unsigned char * msg, unsigned int len)
{
	//Step 4
	cm_blk(cm, msg, len);
}

unsigned int crc32_pack_end(p_cm_t cm, unsigned char * msg, unsigned int len)
{
	if(len > 0)
	{
		//Step 4
		cm_blk(cm, msg, len);
	}

	//Step 5
	return (unsigned int)cm_crc(cm);
}

//crc32 较短的数据，直接使用此函数即可
unsigned int crc32(unsigned char* buf, unsigned char len)
{
	//Step 1
	cm_t cm;

	//Step 2
	cm.cm_width = 32;
	cm.cm_poly  = 0x04C11DB7L; 
	cm.cm_init  = 0xFFFFFFFFL;
	cm.cm_refin = TRUE;
	cm.cm_refot = TRUE;
	cm.cm_xorot = 0xFFFFFFFFL; 

	//Step 3
	cm_ini(&cm);

	//Step 4
	cm_blk(&cm, buf, len);

	//Step 5
	return cm_crc(&cm);
}

/******************************************************************************/
/*                             End of crcmodel.c                              */
/******************************************************************************/
