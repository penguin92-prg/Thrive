#pragma once

#include <Arduino.h>

#include <stdint.h>

namespace robot::atmega{
  static constexpr uint8_t LINE_NUM_ANGEL = 32;
  static constexpr uint8_t LINE_NUM_SIDE = 2;

  static constexpr uint8_t PIN_THRESHOLDs[4] = {2, 3, 4, 5};
  static constexpr uint8_t FRONTRIGHT = 0;
  static constexpr uint8_t BACKRIGHT = 1;
  static constexpr uint8_t BACKLEFT = 2;
  static constexpr uint8_t FRONTLEFT = 3;

  static constexpr uint8_t PIN_LEDs[2] = {25, 26};
}

namespace robot{
  class Atmega{
   private:
    bool m_signals_angel[32] = {};
    bool m_signals_side[2] = {};
    uint8_t m_thresholds[4] = {90, 90, 90, 90};
   public:
    Atmega() = default;
    ~Atmega() = default;

    void init();
    void update();

    void setThreshold(uint8_t pin, uint8_t value);

    const bool (&getLineAngel())[robot::atmega::LINE_NUM_ANGEL];
    const bool (&getLineSide())[robot::atmega::LINE_NUM_SIDE];
  };
}