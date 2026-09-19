#include "line.hpp"

Line line;

void Line::init(int baudrate){
  Serial1.begin(baudrate);
  Serial.println("Line Initialized");
  return;
}

void Line::receive(uint8_t receivetype){
  switch(receivetype){
    case ALL:{
      if(Serial1.available() < STR_SIZE[ALL]) return;

      if(Serial1.peek() != STR_HEADER){
        Serial1.read();
        Serial.println("通信エラー! データヘッダが異なります!");
        return;
      }
      Serial1.read();

      uint8_t buf[STR_SIZE[ALL] - 1];
      for(uint8_t i=0; i<STR_SIZE[ALL]-1; i++){
        buf[i] = Serial1.read();
      }

      m_signalAngelRaw = ((uint32_t)buf[0]) | ((uint32_t)buf[1]<<8) | ((uint32_t)buf[2]<<16) | ((uint32_t)buf[3]<<24);
      m_signalSideRaw = buf[4];
      
      for (uint8_t i = 0; i < NUM_ANGEL; i++) {
          signal[i] = (m_signalAngelRaw & (1UL << i)) != 0;
      }

      right = (m_signalSideRaw & (1 << 0)) != 0;
      left  = (m_signalSideRaw & (1 << 1)) != 0;
      signal[NUM_ANGEL + 0] = right;
      signal[NUM_ANGEL + 1] = left;

      while(Serial1.available() > 0){
        Serial1.read();
      } 
      return;
    }
    case VECTOR:{
      if(Serial1.available() < STR_SIZE[VECTOR]) return;

      if(Serial1.peek() != STR_HEADER){
        Serial1.read();
        Serial.println("通信エラー! データヘッダが異なります!");
        return;
      }
      Serial1.read();

      uint8_t buf[STR_SIZE[VECTOR] - 1];
      for(uint8_t i=0; i<STR_SIZE[VECTOR]-1; i++){
        buf[i] = Serial1.read();
      }

      FloatByte receiveDir;
      receiveDir.bytes[0] = buf[0];
      receiveDir.bytes[1] = buf[1];
      receiveDir.bytes[2] = buf[2];
      receiveDir.bytes[3] = buf[3];
      dir = receiveDir.f;
      
      FloatByte receiveDistance;
      receiveDistance.bytes[0] = buf[4];
      receiveDistance.bytes[1] = buf[5];
      receiveDistance.bytes[2] = buf[6];
      receiveDistance.bytes[3] = buf[7];
      distance = receiveDistance.f;
      
      while(Serial1.available() > 0){
        Serial1.read();
      }

      return;
    }
  }
}

void Line::calc(){
  // 初期化
  vec.clear();
  num = 0;
  area = 0;
  int index = 0;
  Vec2 v[NUM_ANGEL];
  int count[NUM_ANGEL];
  for(uint8_t i=0; i<NUM_ANGEL; i++){
    v[i].x = 0;
    v[i].y = 0;
    count[i] = 0;
  }

  // エンジェルリングの反応センサ数を算出
  for(uint8_t i=0; i<NUM_ANGEL; i++){
    if(signal[i]) num++;
  }

  // サイドの白線検知の有無を調べる
  right = signal[NUM_ANGEL+0];
  left = signal[NUM_ANGEL+1];

  // エンジェルリングのサイドの白線検知の有無を調べる
  onAngel = num > 0;
  onSide = right || left;

  // 論理和で白線検知の有無を調べる
  on = onAngel | onSide;

  // 白線を検知していない場合は処理をスキップ
  if(!on) return;

  // 白線検知部分
  if(!onAngel){
    if(right) vec.y = -1;
    if(left) vec.y = 1;
  }
  else{
    // エンジェルリングも白線を検知している場合
    for(uint8_t i=0; i<NUM_ANGEL; i++){
      // もしi番目のセンサが反応していたら
      if(signal[i]){
        // i番目のセンサの取り付け角を算出
        // 360.0fを360としてしまうとradiansの引数が整数になってしまうので要注意
        float sensorDir = radians(i*360.0f/NUM_ANGEL);
        v[index].x += cos(sensorDir);
        v[index].y += sin(sensorDir);
        // あとで平均をとるためにカタマリに含むセンサ個数のカウントを増やす
        count[index]++;
      }

      // 今のセンサが反応 ⋀ 次のセンサが反応していない → カタマリが切れたとみなす → indexを加算
      // %が出てくるのはmod(NUM_ANGEL)の世界にすることですべての数字を0-31に落とし込むことができるから
      if(signal[i] && !signal[(i+1)%NUM_ANGEL]) index++;
    }

    // 切れ目（1個目と32個目）の処理
    if(signal[NUM_ANGEL-1] && signal[0]){
      v[0] += v[index-1];
      count[0] += count[index-1];
      index -= 1;
    }

    // カタマリの数
    area = index;

    // カタマリのベクトルの平均を算出
    // → 白線の方向ベクトルに加算
    for(int i=0; i<index; i++){
      v[i] /= (float)count[i];
      vec += v[i];
    }
  }

  // 角度と距離を算出
  dirPrev = dir;
  dir = -degrees(atan2(vec.y, vec.x));
  if(index == 0) index = 1;
  distance = vec.len() / (float)index;

  // 踏み始めならdirPrevをdirに一致させる
  if(onPrev == false && on == true) dirPrev = dir;

  // 前回検出角度との差分を算出
  float diff = abs(dir - dirPrev);
  if(diff > 180.0f) diff = 360.0f - diff;

  // 1ループ前から30度以上検出角が変化した場合はdirをdirPrevに一致させる
  // （白線を超過したときのため）
  if(diff > 30) dir = dirPrev;

  onPrev = on;

  return;
}