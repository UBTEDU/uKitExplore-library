/* 
 * UKIT Advanced  
 * <Circuitry> 
 * IR_Sensor
 */  
 
#include"UKIT_Advance.h" 
#include "IRremote.h"

long ir_item;
IRrecv irrecv_37(37);
decode_results results_37;

void setup() {
    Initialization();
    irrecv_37.enableIRIn();
}
void loop() {
    if (irrecv_37.decode(&results_37)) {
      ir_item=results_37.value;
      String type="UNKNOWN";
      String typelist[14]={"UNKNOWN", "NEC", "SONY", "RC5", "RC6", "DISH", "SHARP", "PANASONIC", "JVC", "SANYO", "MITSUBISHI", "SAMSUNG", "LG", "WHYNTER"};
      if(results_37.decode_type>=1&&results_37.decode_type<=13){
        type=typelist[results_37.decode_type];
      }
      Serial.print("IR TYPE:"+type+"  ");//Print output data 
        Serial.println(ir_item,HEX);//Print output data 
      irrecv_37.resume();
    } else {
    }
}
