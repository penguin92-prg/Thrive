#include "camera.hpp"

void setup() {
  Serial.begin(115200);
  camera.init(115200);
}

void loop() {
  camera.receive(Serial4);
  camera.send(Serial);

  delay(10);
}
