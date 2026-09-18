#include "buzzer.hpp"

Buzzer buzzer;

void Buzzer::init(){
  pinMode(PIN, OUTPUT);
  Serial.println("Buzzer Initialized");
}

void Buzzer::update(){
  if(!isPlaying) return;

  uint32_t currentMillis = millis();
  
  if(currentMillis - previousMillis >= MELODY[noteIndex].duration){
    previousMillis = currentMillis;
    noteIndex++;

    if(noteIndex >= MELODY_LEN){
      noteIndex = 0;
      isPlaying = false;
      return;
    }

    if(MELODY[noteIndex].frequency == 0){
      noTone(PIN);
    }
    else{
      tone(PIN, MELODY[noteIndex].frequency);
    }
  }
  return;
}

void Buzzer::play(uint8_t num){
  isPlaying = true;
  melodyNum = num;
  noteIndex = 0;

  previousMillis = millis();

  if (MELODY[0].frequency == 0) {
    noTone(PIN);
  } else {
    tone(PIN, MELODY[0].frequency);
  }

  return;
}