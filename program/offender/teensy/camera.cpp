#include "camera.hpp"

Camera cameras[4] = {Camera(0), Camera(1), Camera(2), Camera(3)};
// Camera camera4(4);

void Camera::init(int baudrate){
  // 配列の範囲外アクセス防止ガード
  if (cameraNum >= 5) {
    Serial.print("Camera No. is Invalid: ");
    Serial.println(cameraNum);
    camSerial = nullptr;
    return;
  }

  camSerial = CAMERA_SERIAL[cameraNum];
  camSerial->begin(baudrate);

  Serial.print("Camera");
  Serial.print(cameraNum);
  Serial.println(" Initialized");
}

void Camera::receive(){
  // 未初期化・無効なカメラをブロック
  if (camSerial == nullptr) return;

  // 受信バッファにたまっているデータ長（byte）
  uint8_t avail = camSerial->available();

  // 受信バッファのデータ長が想定データ長より短い場合は処理を中断
  if(avail < STR_SIZE){
    if(avail == 0){
      Serial.print("No Data Received: camera");
      Serial.println(cameraNum);
      return;
    }
    Serial.print("Not Enough Data Received: camera");
    Serial.println(cameraNum);
    return;
  }

  // 最新のデータ以外を破棄
  while(camSerial->available() > STR_SIZE){
    camSerial->read();
  }

  // 最新データを1byteずつ格納
  uint8_t x[2];
  uint8_t y;
  x[0] = camSerial->read();
  x[1] = camSerial->read();
  y = camSerial->read();

  // エラー値処理
  data.x = ((x[0] << 8) | x[1]) == 512 ? -1 : ((x[0] << 8) | x[1]);
  data.y = y == 255 ? -1 : y;
  return;
}

void Camera::send(){
  // カメラへのデータ送信
}

Ball Camera::calc(){
  Ball ball;

  if(data.x == -1 || data.y == -1){
    ball.isExist = false;
    return ball;
  }

  ball.isExist = true;
  
  // カメラ設置角度を算出
  cameraDeg.y = 90*cameraNum;
  
  // カメラ設置座標を算出
  float cameraRadY = cameraDeg.y / 180.0f * 3.14159265;
  cameraPos.x = 0.05*sin(cameraRadY);
  cameraPos.y = 0.11;
  cameraPos.z = 0.05*cos(cameraRadY);
  
  // ボール位置をカメラからの相対座標に変換
  ball3.x = data.x - cameraCenter.x;
  ball3.y = data.y - cameraCenter.y;
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

  // コート上での2次元座標の算出
  court.x = cameraPos.x + d.x * t;
  court.y = cameraPos.z + d.z * t;

  // ボールの角度を算出
  float deg = atan2(court.y, court.x) * 180.0f / 3.14159265;
  deg = deg > 180 ? deg-360 : deg < -180 ? deg+360 : deg;

  ball.dir = deg;
  ball.distance = court.len();

  return ball;
}