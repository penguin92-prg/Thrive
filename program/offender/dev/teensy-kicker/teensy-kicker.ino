#include "teensy.hpp"

robot::Teensy teensyBoard;

void setup() {

  teensyBoard.init();
  
  Serial.begin(115200);
}

void loop() {
  digitalWrite(robot::pin::teensy::KICKER_STROKE, HIGH);    
  digitalWrite(robot::pin::teensy::KICKER_CHIP, HIGH);
  Serial.println("Kick Start!");
  delay(50);
  digitalWrite(robot::pin::teensy::KICKER_STROKE, LOW);
  digitalWrite(robot::pin::teensy::KICKER_CHIP, LOW);
  Serial.println("Kick Stop!");
  delay(5000);
}