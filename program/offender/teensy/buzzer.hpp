#pragma once

#include <Arduino.h>

#ifndef NOTE_C4
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#endif

class Buzzer{
  private:
    static constexpr uint8_t PIN = 2;

    struct Note{
      int frequency;
      uint32_t duration;
    };

    static constexpr Note MELODY[]{
      {NOTE_C4, 250},
      {NOTE_D4, 250},
      {NOTE_E4, 250},
      {NOTE_F4, 250},
      {NOTE_G4, 250},
      {NOTE_A4, 250},
      {NOTE_B4, 250},
      {NOTE_C5, 500}
    };
    const int MELODY_LEN = sizeof(MELODY) / sizeof(MELODY[0]);
    
    uint8_t melodyNum = 0;
    int noteIndex = 0;
    uint32_t previousMillis = 0;
    bool isPlaying = false;

  public:
    // メロディー名とメロディー番号
    static constexpr uint8_t INIT = 0;

    Buzzer() = default;
    ~Buzzer() = default;

    void init();
    void update();

    void play(uint8_t num);
};

extern Buzzer buzzer;