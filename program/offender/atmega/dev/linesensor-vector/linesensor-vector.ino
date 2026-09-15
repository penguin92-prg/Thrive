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
    Serial.print(line.dir);
    Serial.print("\t");
  }
  else{
    Serial.print("-");
    Serial.print("\t");
  }
  Serial.println();
}