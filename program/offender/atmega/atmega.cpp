#include "atmega.hpp"

namespace robot{
  void Atmega::init(){
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
    for(auto p : robot::atmega::PIN_LEDs){
      pinMode(p, OUTPUT);
    }

    // Serial (With Teensy)
    Serial2.begin(115200);

    // Serial (With PC)
    Serial.begin(115200);
    Serial.println("ATmega2560 Initialization Completed!");
  }

  // Update (call this function at the end of every loop)
  void Atmega::update(){
    // Output Thresholds by PWM
    for(uint8_t i=0; i<4; i++){
      analogWrite(robot::atmega::PIN_THRESHOLDs[i], m_thresholds[i]);
    }

    // Read Registers
    uint32_t value = 0;
    uint8_t value_side = 0;

    const uint8_t a = PINA;
    const uint8_t b = PINB;
    const uint8_t c = PINC;
    const uint8_t d = PIND;
    const uint8_t f = PINF;
    const uint8_t g = PING;
    const uint8_t h = PINH;
    const uint8_t j = PINJ;
    const uint8_t l = PINL;

    value |= ((b >> PB7) & 1UL) << 0;
    value |= ((b >> PB6) & 1UL) << 1;
    value |= ((b >> PB5) & 1UL) << 2;
    value |= ((b >> PB4) & 1UL) << 3;
    value |= ((b >> PB0) & 1UL) << 4;

    value |= ((h >> PH6) & 1UL) << 5;
    value |= ((h >> PH5) & 1UL) << 6;
    value |= ((h >> PH4) & 1UL) << 7;
    value |= ((h >> PH3) & 1UL) << 8;
    value |= ((h >> PH2) & 1UL) << 9;

    value |= ((f >> PF6) & 1UL) << 10;
    value |= ((f >> PF7) & 1UL) << 11;
    value |= ((a >> PA1) & 1UL) << 12;
    value |= ((a >> PA2) & 1UL) << 13;
    value |= ((j >> PJ6) & 1UL) << 14;

    value |= ((j >> PJ5) & 1UL) << 15;
    value |= ((j >> PJ4) & 1UL) << 16;
    value |= ((j >> PJ3) & 1UL) << 17;
    value |= ((c >> PC5) & 1UL) << 18;
    value |= ((c >> PC4) & 1UL) << 19;

    value |= ((c >> PC3) & 1UL) << 20;
    value |= ((c >> PC2) & 1UL) << 21;
    value |= ((c >> PC1) & 1UL) << 22;
    value |= ((c >> PC0) & 1UL) << 23;
    value |= ((g >> PG1) & 1UL) << 24;

    value |= ((g >> PG0) & 1UL) << 25;
    value |= ((l >> PL3) & 1UL) << 26;
    value |= ((l >> PL2) & 1UL) << 27;
    value |= ((l >> PL1) & 1UL) << 28;
    value |= ((l >> PL0) & 1UL) << 29;
    
    value |= ((g >> PG3) & 1UL) << 30;
    value |= ((h >> PH7) & 1UL) << 31;

    // ========================================
    value_side |= ((f >> PF2) & 1UL) << 0;
    value_side |= ((d >> PD7) & 1UL) << 1;

    for(uint8_t i=0; i<32; i++){
      m_signals_angel[i] = (value & (1UL << i)) != 0;
    }

    for(uint8_t i=0; i<2; i++){
      m_signals_side[i] = (value_side & 1UL << i) != 0;
    }
  }

  // ========================================

  // Set Threshold
  void Atmega::setThreshold(uint8_t position, uint8_t value){
    m_thresholds[position] = value;
    return;
  }

  // Get Signals of AngelRing
  const bool (&Atmega::getLineAngel())[robot::atmega::LINE_NUM_ANGEL] {
    return m_signals_angel;
  }

  // Get Signals of Side Linesensor
  const bool (&Atmega::getLineSide())[robot::atmega::LINE_NUM_SIDE] {
    return m_signals_side;
  }
}