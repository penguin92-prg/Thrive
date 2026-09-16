#include "camera.hpp"

Camera camera;

void Camera::init(int baudrate){
  Serial4.begin(baudrate);
  Serial5.begin(baudrate);
  Serial6.begin(baudrate);
  Serial7.begin(baudrate);
  Serial8.begin(baudrate);
}

void Camera::receive(HardwareSerialIMXRT& camSerial){
  if(camSerial.available() < STR_SIZE) return;

  while(camSerial.available() > STR_SIZE){
    camSerial.read();
  }

  while(camSerial.available()){
    if(camSerial.read() == 0b00000000) break;
  }

  while(camSerial.available() < STR_SIZE) continue;

  for(uint8_t i=0; i<STR_SIZE; i++){
    Serial.print((char)camSerial.read());
  }
  Serial.println();
}

void Camera::send(HardwareSerialIMXRT& serial){
  serial.println("serial");
}