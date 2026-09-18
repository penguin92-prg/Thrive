#include "buzzer.hpp"

void setup() {
  Serial.begin(115200);
  Serial.println("Teensy Initialized");

  buzzer.init();
  buzzer.play(Buzzer::INIT);
}

void loop() {
  buzzer.update();
}