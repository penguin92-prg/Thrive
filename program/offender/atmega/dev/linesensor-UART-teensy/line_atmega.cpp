#include "line_atmega.hpp"

Line line;

void Line::init(int baudrate){
  // INPUT & PULLUP ON
  constexpr uint8_t MASK_A =
    (1 << PA1) |
    (1 << PA2);
  DDRA  &= ~MASK_A;   // INPUT
  PORTA |=  MASK_A;   // PULLUP ON

  constexpr uint8_t MASK_B =
    (1 << PB7) |
    (1 << PB6) |
    (1 << PB5) |
    (1 << PB4) |
    (1 << PB0);
  DDRB  &= ~MASK_B;
  PORTB |=  MASK_B;

  constexpr uint8_t MASK_C =
    (1 << PC5) |
    (1 << PC4) |
    (1 << PC3) |
    (1 << PC2) |
    (1 << PC1) |
    (1 << PC0);
  DDRC  &= ~MASK_C;
  PORTC |=  MASK_C;

  constexpr uint8_t MASK_D =
    (1 << PD7);
  DDRD &= ~MASK_D;
  PORTD |= MASK_D;

  constexpr uint8_t MASK_F =
    (1 << PF2) |
    (1 << PF6) |
    (1 << PF7);
  DDRF  &= ~MASK_F;
  PORTF |=  MASK_F;

  constexpr uint8_t MASK_G =
    (1 << PG1) |
    (1 << PG0) |
    (1 << PG3);
  DDRG  &= ~MASK_G;
  PORTG |=  MASK_G;

  constexpr uint8_t MASK_H =
    (1 << PH6) |
    (1 << PH5) |
    (1 << PH4) |
    (1 << PH3) |
    (1 << PH2) |
    (1 << PH7);
  DDRH  &= ~MASK_H;
  PORTH |=  MASK_H;

  constexpr uint8_t MASK_J =
    (1 << PJ6) |
    (1 << PJ5) |
    (1 << PJ4) |
    (1 << PJ3);
  DDRJ  &= ~MASK_J;
  PORTJ |=  MASK_J;

  constexpr uint8_t MASK_L =
    (1 << PL3) |
    (1 << PL2) |
    (1 << PL1) |
    (1 << PL0);
  DDRL  &= ~MASK_L;
  PORTL |=  MASK_L;

  // LED
  for(auto p : PIN_LED){
    pinMode(p, OUTPUT);
  }

  for(uint8_t i=0; i<4; i++){
    analogWrite(PIN_THRESHOLD[i], threshold[i]);
  }

  // Serial (With Teensy)
  Serial2.begin(baudrate);

  // Serial (With PC)
  Serial.begin(115200);
  Serial.println("ATmega2560 Initialization Completed!");
}

// Read all sensors
void Line::read(){
  // Read Registers
  m_signalAngelRaw = 0;
  m_signalSideRaw = 0;

  const uint8_t a = PINA;
  const uint8_t b = PINB;
  const uint8_t c = PINC;
  const uint8_t d = PIND;
  const uint8_t f = PINF;
  const uint8_t g = PING;
  const uint8_t h = PINH;
  const uint8_t j = PINJ;
  const uint8_t l = PINL;

  m_signalAngelRaw |= ((b >> PB7) & 1UL) << 0;
  m_signalAngelRaw |= ((b >> PB6) & 1UL) << 1;
  m_signalAngelRaw |= ((b >> PB5) & 1UL) << 2;
  m_signalAngelRaw |= ((b >> PB4) & 1UL) << 3;
  m_signalAngelRaw |= ((b >> PB0) & 1UL) << 4;

  m_signalAngelRaw |= ((h >> PH6) & 1UL) << 5;
  m_signalAngelRaw |= ((h >> PH5) & 1UL) << 6;
  m_signalAngelRaw |= ((h >> PH4) & 1UL) << 7;
  m_signalAngelRaw |= ((h >> PH3) & 1UL) << 8;
  m_signalAngelRaw |= ((h >> PH2) & 1UL) << 9;

  m_signalAngelRaw |= ((f >> PF6) & 1UL) << 10;
  m_signalAngelRaw |= ((f >> PF7) & 1UL) << 11;
  m_signalAngelRaw |= ((a >> PA1) & 1UL) << 12;
  m_signalAngelRaw |= ((a >> PA2) & 1UL) << 13;
  m_signalAngelRaw |= ((j >> PJ6) & 1UL) << 14;

  m_signalAngelRaw |= ((j >> PJ5) & 1UL) << 15;
  m_signalAngelRaw |= ((j >> PJ4) & 1UL) << 16;
  m_signalAngelRaw |= ((j >> PJ3) & 1UL) << 17;
  m_signalAngelRaw |= ((c >> PC5) & 1UL) << 18;
  m_signalAngelRaw |= ((c >> PC4) & 1UL) << 19;

  m_signalAngelRaw |= ((c >> PC3) & 1UL) << 20;
  m_signalAngelRaw |= ((c >> PC2) & 1UL) << 21;
  m_signalAngelRaw |= ((c >> PC1) & 1UL) << 22;
  m_signalAngelRaw |= ((c >> PC0) & 1UL) << 23;
  m_signalAngelRaw |= ((g >> PG1) & 1UL) << 24;

  m_signalAngelRaw |= ((g >> PG0) & 1UL) << 25;
  m_signalAngelRaw |= ((l >> PL3) & 1UL) << 26;
  m_signalAngelRaw |= ((l >> PL2) & 1UL) << 27;
  m_signalAngelRaw |= ((l >> PL1) & 1UL) << 28;
  m_signalAngelRaw |= ((l >> PL0) & 1UL) << 29;
  
  m_signalAngelRaw |= ((g >> PG3) & 1UL) << 30;
  m_signalAngelRaw |= ((h >> PH7) & 1UL) << 31;

  // ========================================
  m_signalSideRaw |= ((f >> PF2) & 1UL) << 0;
  m_signalSideRaw |= ((d >> PD7) & 1UL) << 1;

  for(uint8_t i=0; i<NUM_ANGEL; i++){
    signal[i] = (m_signalAngelRaw & (1UL << i)) != 0;
  }

  for(uint8_t i=0; i<NUM_SIDE; i++){
    signal[i+NUM_ANGEL] = (m_signalSideRaw & 1UL << i) != 0;
  }
}

// ========================================

// Calculate Vector
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
  
  // エンジェルリングの反応素子数を算出
  for(uint8_t i=0; i<NUM_ANGEL; i++){
    if(signal[i]) num++;
  }

  // サイドの白線検知の有無を調べる
  right = signal[NUM_ANGEL+0];
  left = signal[NUM_ANGEL+1];

  // エンジェルリングとサイドの白線検知の有無を調べる
  onAngel = num > 0;
  onSide = right || left;
  
  // 論理和で白線検知の有無を調べる
  on = onAngel | onSide;

  // 白線を検知していない場合は処理をスキップ
  if(!on) return;

  // 反応検知部分
  if(!onAngel){
    // サイドだけが白線を検知している場合
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
        float sensor_dir = radians(i*360.0f/NUM_ANGEL);
        v[index].x += cos(sensor_dir);
        v[index].y += sin(sensor_dir);
        // あとで平均をとるためにカタマリに含む個数のカウントを増やす
        count[index]++;
      }
  
      // 今のセンサが反応 ⋀ 次のセンサが反応していない → カタマリが切れたとみなす → indexを加算
      // %が出てくるのはmod(NUM_ANGEL)の世界にすることですべての数字を0-31に落とし込むことができるから
      if(signal[i] && !signal[(i+1)%NUM_ANGEL]) index++;
    }
  
    // 切れ目（1個目と32個目）の処理
    if(signal[NUM_ANGEL-1] && signal[0]){
      v[0] += v[index];
      count[0] += count[index];
      index -= 1;
    }
  
    // カタマリの数
    area = index;
  
    // カタマリのベクトルの平均を算出
    // → 白線の方向ベクトルに加算
    for(int i=0;i<index;i++){
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
  if(onPrev == false && on == true){
    dirPrev = dir;
  }

  // 1ループ前から30度以上検出角が変化した場合はdirPrevをdirに一致させる
  // （白線を超過したときのため）
  float diff = abs(dir - dirPrev);
  if(diff > 30){
    dir = dirPrev;
  }
}

// ========================================

// Set Threshold
void Line::setThreshold(uint8_t position, uint8_t value){
  threshold[position] = value;
  analogWrite(PIN_THRESHOLD[position], threshold[position]);
  return;
}

// ========================================

void Line::sendAll(){
  uint8_t sendList[STR_SIZE_SENDALL];

  // ヘッダ
  // sendList[0] = 0b10101010
  sendList[0] = 0xAA;

  // エンジェルリングのデータをLittleEndian形式で送信
  // sendList[1] = 0bxxxxxxxx → 前xxx右前xxx
  // sendList[2] = 0bxxxxxxxx → 右xxx右後xxx
  // sendList[3] = 0bxxxxxxxx → 後xxx左後xxx
  // sendList[4] = 0bxxxxxxxx → 左xxx左前xxx
  sendList[1] = (uint8_t)(m_signalAngelRaw & 0xFF);
  sendList[2] = (uint8_t)((m_signalAngelRaw >> 8) & 0xFF);
  sendList[3] = (uint8_t)((m_signalAngelRaw >> 16) & 0xFF);
  sendList[4] = (uint8_t)((m_signalAngelRaw >> 24) & 0xFF);

  // サイド
  // sendList[5] = 0b000000xx → 000000左右
  sendList[5] = (uint8_t)(m_signalSideRaw & 0xFF);

  Serial2.write(sendList, STR_SIZE_SENDALL);
  return;
}

void Line::send(){
  uint8_t sendList[STR_SIZE_SEND];

  // ヘッダ
  sendList[0] = 0xAA;
  
  // 角度
  FloatByte sendDir;
  sendDir.f = dir;
  sendList[1] = sendDir.bytes[0];
  sendList[2] = sendDir.bytes[1];
  sendList[3] = sendDir.bytes[2];
  sendList[4] = sendDir.bytes[3];

  // 距離
  FloatByte sendDistance;
  sendDistance.f = distance;
  sendList[5] = sendDistance.bytes[0];
  sendList[6] = sendDistance.bytes[1];
  sendList[7] = sendDistance.bytes[2];
  sendList[8] = sendDistance.bytes[3];

  Serial2.write(sendList, STR_SIZE_SEND);
  return;
}