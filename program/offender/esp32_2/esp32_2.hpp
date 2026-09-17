#pragma once

#include <Arduino.h>

#include <cstdint>
#include <array>

namespace robot{
  class ESP32_2{
   public:
    ESP32_2() = default;
    ~ESP32_2() = default;

    void init();
  }
}

namespace robot::pin::esp32_2{
  static constexpr std::array<uint8_t, 4> USSs = {D0, D1, D2, D3};
  static constexpr uint8_t USS_EN = D4;

  static constexpr std::array<uint8_t, 2> SWITCH_TOGGLEs = {D5, D8};

  static constexpr uint8_t NEOPIXEL = D10;

  static constexpr uint8_t UART_TX = D6;
  static constexpr uint8_t UART_RX = D7;
}