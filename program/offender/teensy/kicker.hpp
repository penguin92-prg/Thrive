#pragma once

#include <Arduino.h>

class Kicker{
  private:
    static constexpr uint8_t PIN_STROKE = 30;
    static constexpr uint8_t PIN_CHIP = 31;

    // キック間隔
    static constexpr uint32_t INTERVAL = 3000;

    // 直近にキックした時刻
    uint32_t strokeKickTime = 0;
    uint32_t chipKickTime = 0;

  public:
    Kicker() = default;
    ~Kicker() = default;

    void init();
    void strokeKick();
    void chipKick();
};

extern Kicker kicker;