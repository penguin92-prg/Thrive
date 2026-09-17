#include "atmega.hpp"

robot::Atmega atmegaBoard;

void setup() {
  // put your setup code here, to run once:
  atmegaBoard.init();
}

void loop() {
  const auto& lineAngel = atmegaBoard.getLineAngel();
  const auto& lineSide = atmegaBoard.getLineSide();

  Serial.print("|  ");

  for(uint8_t i=0; i<robot::atmega::LINE_NUM_ANGEL; i++){
    Serial.print("sig");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.print(lineAngel[i] == 1 ? "○" : "●");
    Serial.print("  |  ");
  }

  Serial.print("|  ");

  for(uint8_t i=0; i<robot::atmega::LINE_NUM_SIDE; i++){
    Serial.print("sig");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.print(lineSide[i]);
    Serial.print("  |  ");
  }
  Serial.println();

  atmegaBoard.update();
}