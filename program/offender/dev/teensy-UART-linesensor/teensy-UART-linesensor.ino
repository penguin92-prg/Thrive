#include "teensy.hpp"

robot::Teensy teensyBoard;

void setup() {
  teensyBoard.init();
}

void loop() {
  if(Serial1.available()){
    Serial.println(Serial1.read());
  }

  delay(10);
}
