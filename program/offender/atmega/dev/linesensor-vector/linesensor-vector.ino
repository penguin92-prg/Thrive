#include "vec2.hpp"
#include "line.hpp"

void setup() {
  // put your setup code here, to run once:
  line.init(115200);
}

void loop() {
  line.read();
  line.calc();
  
  if(line.on){
    Serial.print(line.dir, 4);
    Serial.print("\t");
    Serial.print(line.area);
    Serial.print("\t");
  }
  else{
    Serial.print("-");
    Serial.print("\t");
  }

  for(uint8_t i=0; i<32; i++){
    Serial.print(line.signal[i]);
  }

  Serial.println();
}