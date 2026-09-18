#include "camera.hpp"

void setup() {
  Serial.begin(115200);
  Serial.println("Serial Initialized");

  camera0.init(115200);
}

void loop() {  
  camera0.receive();
  delay(10);
}