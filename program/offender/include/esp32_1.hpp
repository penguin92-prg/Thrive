#pragma once

#include <Arduino.h>

#include <cstdint>
#include <array>

namespace robot{
  class ESP32_1{
   public:
    ESP32_1() = default;
    ~ESP32_1() = default;

    void init();
  };
}

namespace robot::pin::esp32_1{
  static constexpr std::array<uint8_t, 4> IRs = {A0, A1, A2, A3};

  static constexpr std::array<uint8_t, 4> SWITCH_TACTILEs = {D8, D10};

  static constexpr uint8_t UART_TX = D6;
  static constexpr uint8_t UART_RX = D7;
}