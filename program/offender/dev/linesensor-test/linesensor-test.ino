#include "atmega.hpp"

robot::Atmega atmegaBoard;

void setup() {
  // put your setup code here, to run once:
  atmegaBoard.init();

  Serial.begin(115200);

  for(uint8_t i=0; i<4; i++){
    atmegaBoard.setThreshold(i, 100);
  }
}

void loop() {
  for(uint8_t i=0; i<32; i++){
    Serial.print(digitalRead(robot::pin::atmega::SIG_ANGELs[i]));
    Serial.print("\t");
  }

  for(uint8_t i=0; i<2; i++){
    Serial.print(digitalRead(robot::pin::atmega::SIG_SIDEs[i]));
    Serial.print("\t");
  }

  Serial.println();

  atmegaBoard.update();
  
  delay(10);
}