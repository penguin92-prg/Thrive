#include "line.hpp"

void setup() {
  Serial.begin(115200);
  Serial.println("Teensy initialized");

  line.init(115200);
}

void loop() {
  line.receive(Line::ALL);
  
  for(uint8_t i=0; i<32; i++){
    Serial.print(line.signal[i]);
    if(i%5 == 0) Serial.print(" ");
  }

  Serial.print("\t");

  for(uint8_t i=0; i<2; i++){
    Serial.print(line.signal[i+32]);
  }
  
  Serial.println();
}
