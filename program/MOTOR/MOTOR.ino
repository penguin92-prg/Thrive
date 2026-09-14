#include <Arduino.h>
#include <math.h>
void setup() {
  pinMode(6, OUTPUT);
  for(int i=9; i<13; i++){
    pinMode(i, OUTPUT);
    analogWriteFrequency(i, 40000);
  }

  Serial.begin(115200);

  
}

int Move_deg = 0; //動く角度
int MOTOR_POWER = 100;//モーターの出力
int M1;
int M2;
int M3;
int M4;

void MOTOR(){ 
  M1 = static_cast<int>(sin((315 - Move_deg) * PI / 180) * (MOTOR_POWER * 1.27)) + 128;
  M2 = static_cast<int>(sin((225 - Move_deg) * PI / 180) * (MOTOR_POWER * 1.27)) + 128;
  M3 = static_cast<int>(sin((135 - Move_deg) * PI / 180) * (MOTOR_POWER * 1.27)) + 128;
  M4 = static_cast<int>(sin((45 - Move_deg) * PI / 180) * (MOTOR_POWER * 1.27)) + 128;
  analogWrite(9,M1);
  analogWrite(10,M2);
  analogWrite(11,M3);
  analogWrite(12,M4);
  return;
}   

void loop() {
  digitalWrite(6,HIGH);
  for(Move_deg=0; Move_deg<360; Move_deg++){
    MOTOR();
    delay(10);
  }
  Move_deg = 0;
  //MOTOR();
  //Serial.println(M1);
}
