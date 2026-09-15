#include "line.hpp"

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
  m_signals_angel_raw = 0;
  m_signals_side_raw = 0;

  const uint8_t a = PINA;
  const uint8_t b = PINB;
  const uint8_t c = PINC;
  const uint8_t d = PIND;
  const uint8_t f = PINF;
  const uint8_t g = PING;
  const uint8_t h = PINH;
  const uint8_t j = PINJ;
  const uint8_t l = PINL;

  m_signals_angel_raw |= ((b >> PB7) & 1UL) << 0;
  m_signals_angel_raw |= ((b >> PB6) & 1UL) << 1;
  m_signals_angel_raw |= ((b >> PB5) & 1UL) << 2;
  m_signals_angel_raw |= ((b >> PB4) & 1UL) << 3;
  m_signals_angel_raw |= ((b >> PB0) & 1UL) << 4;

  m_signals_angel_raw |= ((h >> PH6) & 1UL) << 5;
  m_signals_angel_raw |= ((h >> PH5) & 1UL) << 6;
  m_signals_angel_raw |= ((h >> PH4) & 1UL) << 7;
  m_signals_angel_raw |= ((h >> PH3) & 1UL) << 8;
  m_signals_angel_raw |= ((h >> PH2) & 1UL) << 9;

  m_signals_angel_raw |= ((f >> PF6) & 1UL) << 10;
  m_signals_angel_raw |= ((f >> PF7) & 1UL) << 11;
  m_signals_angel_raw |= ((a >> PA1) & 1UL) << 12;
  m_signals_angel_raw |= ((a >> PA2) & 1UL) << 13;
  m_signals_angel_raw |= ((j >> PJ6) & 1UL) << 14;

  m_signals_angel_raw |= ((j >> PJ5) & 1UL) << 15;
  m_signals_angel_raw |= ((j >> PJ4) & 1UL) << 16;
  m_signals_angel_raw |= ((j >> PJ3) & 1UL) << 17;
  m_signals_angel_raw |= ((c >> PC5) & 1UL) << 18;
  m_signals_angel_raw |= ((c >> PC4) & 1UL) << 19;

  m_signals_angel_raw |= ((c >> PC3) & 1UL) << 20;
  m_signals_angel_raw |= ((c >> PC2) & 1UL) << 21;
  m_signals_angel_raw |= ((c >> PC1) & 1UL) << 22;
  m_signals_angel_raw |= ((c >> PC0) & 1UL) << 23;
  m_signals_angel_raw |= ((g >> PG1) & 1UL) << 24;

  m_signals_angel_raw |= ((g >> PG0) & 1UL) << 25;
  m_signals_angel_raw |= ((l >> PL3) & 1UL) << 26;
  m_signals_angel_raw |= ((l >> PL2) & 1UL) << 27;
  m_signals_angel_raw |= ((l >> PL1) & 1UL) << 28;
  m_signals_angel_raw |= ((l >> PL0) & 1UL) << 29;
  
  m_signals_angel_raw |= ((g >> PG3) & 1UL) << 30;
  m_signals_angel_raw |= ((h >> PH7) & 1UL) << 31;

  // ========================================
  m_signals_side_raw |= ((f >> PF2) & 1UL) << 0;
  m_signals_side_raw |= ((d >> PD7) & 1UL) << 1;

  for(uint8_t i=0; i<NUM_ANGEL; i++){
    signal[i] = (m_signals_angel_raw & (1UL << i)) != 0;
  }

  for(uint8_t i=0; i<NUM_SIDE; i++){
    signal[i+NUM_ANGEL] = (m_signals_side_raw & 1UL << i) != 0;
  }
}

// ========================================

// Calculate Vector
void Line::calc(){

  // Initialization
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
  
  // ON or OFF
  for(uint8_t i=0; i<NUM_ANGEL; i++){
    if(signal[i]){
      num++;
    }
  }
  
  on = num > 0;

  // Proceed Signals in Row All Together
  for(uint8_t i=0; i<NUM_ANGEL; i++){
    if(signal[i]){
      float sensor_dir = radians(i*360/NUM_ANGEL);
      v[index].x += cos(sensor_dir);
      v[index].y += sin(sensor_dir);
      count[index]++;
    }
  }

  // Handle the Break of the Loop
  if(signal[NUM_ANGEL-1] && signal[0]){
    v[0] += v[index];
    count[0] += count[index];
    index -= 1;
  }

  area = index;

  // Sum
  for(int i=0; i<NUM_ANGEL; i++){
    // count[i]--;
    // if(count[i] < 1) count[i] = 1;
    if(count[i] != 0){
      v[i].x /= (float)count[i];
      v[i].y /= (float)count[i];
      vec.x += v[i].x;
      vec.y += v[i].y;
    }
  }

  // Calculate Angle & Distance
  // dir_prev = dir;
  dir = -degrees(atan2(vec.y, vec.x));
  if(index == 0){
    index = 1;
  }
  distance = vec.len() / (float)index;

  // 踏み始め
  // if(prev_on == false && on == true){
  //   dir_prev = dir;
  // }

  // Limit Rapid Change of Direction
  // float diff = abs(dir - dir_prev);
  // if(diff > 30){
  //   dir = dir_prev;
  // }
}

// ========================================

// Set Threshold
void Line::setThreshold(uint8_t position, uint8_t value){
  threshold[position] = value;
  analogWrite(PIN_THRESHOLD[position], threshold[position]);
  return;
}