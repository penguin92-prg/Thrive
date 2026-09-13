#include "teensy.hpp"

namespace robot{
  void Teensy::init(){
    // Motor
    pinMode(robot::pin::teensy::MOTOR_EN, OUTPUT);
    for(auto& MOTOR_PWM : robot::pin::teensy::MOTOR_PWMs){
      pinMode(MOTOR_PWM, OUTPUT);
    }

    // BallCatchSensor
    pinMode(robot::pin::teensy::BALLCATCH_FRONT, INPUT);
    pinMode(robot::pin::teensy::BALLCATCH_BACK, INPUT);

    // Kicker
    pinMode(robot::pin::teensy::KICKER_STROKE, OUTPUT);
    pinMode(robot::pin::teensy::KICKER_CHIP, OUTPUT);

    // Dribbler
    pinMode(robot::pin::teensy::DRIBBLER_FRONT_EN, OUTPUT);
    pinMode(robot::pin::teensy::DRIBBLER_FRONT_PH, OUTPUT);
    pinMode(robot::pin::teensy::DRIBBLER_BACK, OUTPUT);

    // LED
    pinMode(robot::pin::teensy::LED, OUTPUT);
    
    // Serial (With LineSensor)
    Serial1.begin(115200);
    
    // Serial (With ESP32_1)
    Serial2.begin(115200);
    
    // Serial (With ESP32_2)
    Serial3.begin(115200);

    // Serial (With UnitV1)
    Serial4.begin(115200);

    // Serial (With UnitV2)
    Serial5.begin(115200);

    // Serial (With UnitV3)
    Serial6.begin(115200);

    // Serial (With UnitV4)
    Serial7.begin(115200);
    
    // Serial (With UnitV5)
    Serial8.begin(115200);
  }
}