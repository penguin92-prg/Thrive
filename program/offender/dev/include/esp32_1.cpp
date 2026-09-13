#include "esp32_1.hpp"

namespace robot{
  void ESP32_1::init(){
    // Tactile Switch
    for(auto& SWITCH_TACTILE : robot::pin::esp32_1::SWITCH_TACTILEs){
      pinMode(SWITCH_TACTILE, INPUT);
    }
    
    // Serial (With Teensy)
    Serial1.setPins(robot::pin::esp32_1::UART_RX, robot::pin::esp32_1::UART_TX);
    Serial1.begin(115200);
  }
}