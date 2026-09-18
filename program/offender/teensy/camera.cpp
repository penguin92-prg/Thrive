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

  ball.x = ((x[0] << 8) | x[1]) == 512 ? -1 : ((x[0] << 8) | x[1]);

  ball.y = y == 255 ? -1 : y;

  while(camSerial.available() > 0){
    camSerial.read();
  }
  return;
}

void Camera::send(HardwareSerialIMXRT& serial){
  // カメラへのデータ送信
}

float Camera::calcDeg(){
  if(ball.x == -1 || ball.y == -1){
    return -1.0f;
  }
  
  // カメラ設置角度を算出
  cameraDeg.y = 90*cameraNum;
  
  // カメラ設置座標を算出
  float cameraRadY = cameraDeg.y / 180.0f * 3.14159265;
  cameraPos.x = 0.05*sin(cameraRadY);
  cameraPos.y = 0.11;
  cameraPos.z = 0.05*cos(cameraRadY);
  
  // ボール位置をカメラからの相対座標に変換
  ball3.x = ball.x - cameraCenter.x;
  ball3.y = ball.y - cameraCenter.y;
  ball3.z = cameraFocus.x;

  // ベクトルの大きさを1にして単位ベクトルに変換
  float norm = ball3.len();
  ball3 /= norm;
  // if(norm > 0.0001f){
  //   ball3 /= norm;
  // }

  // 回転行列を計算
  d1 = Matrix33::rotZ(cameraDeg.z) * ball3;
  d2 = Matrix33::rotX(cameraDeg.x) * d1;
  d = Matrix33::rotY(cameraDeg.y) * d2;

  // コート床との交点算出
  float t = cameraPos.y / d.y;

  コート上での2次元座標の算出
  court.x = cameraPos.x + d.x * t;
  court.y = cameraPos.z + d.z * t;

  // ボールの角度を算出
  return atan2(ball.y, ball.x) * 180.0f / 3.14159265;
}