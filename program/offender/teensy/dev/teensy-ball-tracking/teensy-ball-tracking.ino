#include "camera.hpp"
#include "motor.hpp"

void setup() {
  Serial.begin(115200);
  Serial.println("Serial Initialized");

  motor.init();
  camera0.init(115200);
}

void loop() {  
  camera0.receive();
  float ballDeg = camera0.calcDeg();
  if(ballDeg == -1){
    motor.set(0, 0, 0, 0);
  }
  else{
    motor.setDeg(ballDeg, 100);
  }
  
  motor.calcAvr();
  motor.output();
}