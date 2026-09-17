#include "camera.hpp"

void setup() {
  Serial.begin(115200);
  Serial.println("Serial Initialized");
  pinMode(16, INPUT_PULLUP);
  camera1.init(Serial4, 115200);
  camera1.ball.y = -999;
}

void loop() {
  int avail = Serial4.available();
  
  camera1.receive(Serial4);

  Serial.print("Avail: ");
  Serial.print(avail);
  Serial.print(" | ball.x: ");
  Serial.print(camera1.ball.x);
  Serial.print(" | ball.y: ");
  Serial.println(camera1.ball.y);

  delay(100);
}
