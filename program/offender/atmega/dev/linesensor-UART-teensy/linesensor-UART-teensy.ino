#include "atmega.hpp"

robot::Atmega atmegaBoard;

void setup() {
  atmegaBoard.init();
}

void loop() {
  Serial2.print("a");

  atmegaBoard.update();
  delay(10);
}