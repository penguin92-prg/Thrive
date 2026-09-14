#include "atmega.hpp"

namespace robot{
  void Atmega::init(){
    // Angel Linesensor
    for(auto p : robot::pin::atmega::SIG_ANGELs){
      pinMode(p, INPUT_PULLUP);
    }

    // Side Linesensor
    for(auto p : robot::pin::atmega::SIG_SIDEs){
      pinMode(p, INPUT_PULLUP);
    }

    // LED
    for(auto p : robot::pin::atmega::LEDs){
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
    for(uint8_t i=0; i<4; i++){
      analogWrite(robot::pin::atmega::THRESHOLDs[i], m_thresholds[i]);
    }
  }

  // Set Threshold
  void Atmega::setThreshold(uint8_t position, uint8_t value){
    m_thresholds[position] = value;
    return;
  }
}