#pragma once

#include <Arduino.h>

#include <stdint.h>

namespace robot{
  class Atmega{
   private:
    uint8_t m_thresholds[4] = {128, 128, 128, 128};
   public:
    Atmega() = default;
    ~Atmega() = default;

    void init();
    void update();
    void setThreshold(uint8_t pin, uint8_t value);
  };
}

namespace robot::pin::atmega{
  static constexpr uint8_t LINE_NUM = 32;
  static constexpr uint8_t SIG_ANGELs[robot::pin::atmega::LINE_NUM] = 
    {
      13, 12, 11, 10, 53, 9, 8, 7,
      6, (0), A6, A7, 23, 24, (0), (0),
      (0), (0), 32, 33, 34, 35, 36, 37,
      40, 41, 46, 47, 48, 49, (0), (0)
    };
  
  static constexpr uint8_t LINE_NUM_SIDE = 2;
  static constexpr uint8_t SIG_SIDEs[robot::pin::atmega::LINE_NUM_SIDE] = {A2, 38};

  static constexpr uint8_t THRESHOLDs[4] = {2, 3, 4, 5};

  static constexpr uint8_t LEDs[2] = {25, 26};
}