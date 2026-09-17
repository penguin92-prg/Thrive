#pragma once

#include <cstdint>
#include <array>

namespace robot{
  class Teensy{
   public:
    Teensy() = default;
    ~Teensy() = default;

    void init();
  };
}

namespace robot::pin::teensy{
  static constexpr uint8_t MOTOR_EN = 8;
  static constexpr std::array<uint8_t, 4> MOTOR_PWMs = {9, 10, 11, 12};

  static constexpr uint8_t BALLCATCH_FRONT = 26;
  static constexpr uint8_t BALLCATCH_BACK = 27;

  static constexpr uint8_t KICKER_STROKE = 30;
  static constexpr uint8_t KICKER_CHIP = 31;

  static constexpr uint8_t DRIBBLER_FRONT_EN = 22;
  static constexpr uint8_t DRIBBLER_FRONT_PH = 23;

  static constexpr uint8_t DRIBBLER_BACK = 36;

  static constexpr uint8_t LED = 33;
}