#include "motor.hpp"

Motor motor;

void Motor::init(){
  pinMode(PIN_EN, OUTPUT);
  for(uint8_t i=0; i<NUM; i++){
    analogWriteFrequency(PIN_PH[i], FREQUENCY);
  }
  Serial.println("Motor Initialized");
}

void Motor::output(){
  digitalWrite(PIN_EN, HIGH);
  for(uint8_t i=0; i<NUM; i++){
    motorRaw[i] = motorRaw[i] > 100 ? 100 : motorRaw[i] < -100 ? -100 : motorRaw[i];
    float target = motorRaw[i] * DIR[i];
    uint8_t val = (uint8_t)(127.5f + (target * 127.5f / 100.0f));
    analogWrite(PIN_PH[i], val);
  }
}

// ==================================================

void Motor::calcAvr() {
  static int queueIndex = 0;       // 出力値のキューのインデックス
  static float queueSum[NUM] = {0};  // 各モーターのキュー内の合計値を記録

  for (int i = 0; i < NUM; i++) {
    // キューの合計値から古い値を引き、新しい値を足す
    queueSum[i] -= queue[queueIndex][i];
    queue[queueIndex][i] = motor[i];
    queueSum[i] += motor[i];

    // 平均値を計算
    motorRaw[i] = queueSum[i] / (float)QUEUE_SIZE;
  }

  // インデックスを更新
  queueIndex = (queueIndex + 1) % QUEUE_SIZE;

  return;
}

// ==================================================

void Motor::set(int8_t m0, int8_t m1, int8_t m2, int8_t m3){
  motor[0] = m0;
  motor[1] = m1;
  motor[2] = m2;
  motor[3] = m3;
  return;
}

void Motor::setRaw(int8_t m0, int8_t m1, int8_t m2, int8_t m3){
  motorRaw[0] = m0;
  motorRaw[1] = m1;
  motorRaw[2] = m2;
  motorRaw[3] = m3;
  return;
}

void Motor::setDir(float deg, int8_t power){
  power = power > 100 ? 100 : power < -100 ? -100 : power;

  for(uint8_t i=0; i<NUM; i++){
    uint16_t motorDeg = 90*i + 45;
    motor[i] = (int)(sin((motorDeg - deg) / 180.0f * 3.14159265) * power);
  }
}