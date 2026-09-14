#include "esp32_2.hpp"

namespace robot{
  void ESP32_2::init(){
    // USS Sensor
    for(auto& USS : robot::pin::esp32_2::USSs){
      pinMode(USS, INPUT);
    }
    pinMode(USS_EN, OUTPUT);

    // Toggle Switch
    for(auto& SWITCH_TOGGLE : robot::pin::esp32_2::SWITCH_TOGGLEs){
      pinMode(SWITCH_TOGGLE, INPUT);
    }
    
    // Serial (With Teensy)
    Serial1.setPins(robot::pin::esp32_2::UART_RX, robot::pin::esp32_2::UART_TX);
    Serial1.begin(115200);

    // Serial (With PC)
    Serial.begin(115200);
    Serial.println("ESP32_2 Initialization Completed!");
  }
}