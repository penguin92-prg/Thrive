#include "atmega.hpp"

robot::Atmega atmegaBoard;

void setup() {
  // put your setup code here, to run once:
  atmegaBoard.init();

  Serial.begin(115200);
}

void loop() {
  for(auto p : robot::pin::atmega::LEDs) digitalWrite(p, HIGH);
  delay(200);
  for(auto p : robot::pin::atmega::LEDs) digitalWrite(p, LOW);
  delay(800);
  atmegaBoard.update();
}