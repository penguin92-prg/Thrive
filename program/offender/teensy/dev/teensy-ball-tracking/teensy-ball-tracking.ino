#include "camera.hpp"
#include "ball.hpp"
#include "motor.hpp"

void setup() {
  Serial.begin(115200);
  Serial.println("Serial Initialized");

  motor.init();
  for(auto &cam : cameras){
    cam.init(115200);
  }
}
void loop() {

  for(uint8_t i=0; i<4; i++){
    cameras[i].receive();
    balls[i] = cameras[i].calc();
  }

  ballGlobal.globalize(balls);

  if(!ballGlobal.isExist){
    motor.set(0, 0, 0, 0);
  }
  else{
    motor.setDir(ballGlobal.dir, 50);
  }

  motor.calcAvr();
  motor.output();
}