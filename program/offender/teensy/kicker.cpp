#include "kicker.hpp"

Kicker kicker;

void Kicker::init(){
  pinMode(PIN_STROKE, OUTPUT);
  pinMode(PIN_CHIP, OUTPUT);

  return;
}

void Kicker::strokeKick(){
  bool strokeReady = millis() - strokeKickTime > INTERVAL;
  if(strokeReady){
    digitalWrite(PIN_STROKE, HIGH);
    strokeKickTime = millis();
  }
  return;
}

void Kicker::chipKick(){
  bool strokeReady = millis() - strokeKickTime > INTERVAL;
  bool chipReady = millis() - chipKickTime > INTERVAL;
  if(strokeReady && chipReady){
    digitalWrite(PIN_STROKE, HIGH);
    digitalWrite(PIN_CHIP, HIGH);
    strokeKickTime = millis();
    chipKickTime = millis();
  }
}