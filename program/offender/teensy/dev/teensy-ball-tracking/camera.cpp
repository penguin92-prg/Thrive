#include "camera.hpp"

Camera camera1;
Camera camera2;
Camera camera3;
Camera camera4;
Camera camera5;

void Camera::init(HardwareSerialIMXRT& camSerial, int baudrate){
  camSerial.begin(baudrate);
  Serial.println("Camera Initialized");
}

void Camera::receive(HardwareSerialIMXRT& camSerial){

  // while(camSerial.available() > STR_SIZE){
  //   Serial.println("Larger Data Received");
  //   camSerial.read();
  // }

  while(camSerial.available() < STR_SIZE){
    Serial.println("Not Enough Data");
    continue;
  }

  // if(camSerial.available() == 0){
  //   Serial.println("No Data Received...");
  //   return;
  // }

  uint8_t x[2];
  uint8_t y;
  x[0] = camSerial.read();
  x[1] = camSerial.read();
  y = camSerial.read();

  ball.x = (x[0] << 8) | x[1];

  ball.y = y == 255 ? -1 : y;

  while(camSerial.available() > 0){
    camSerial.read();
  }
  return;
}

void Camera::send(HardwareSerialIMXRT& serial){
  
}