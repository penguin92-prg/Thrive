static constexpr uint8_t STR_SIZE = 4;
static uint8_t uss[4] = {0, 0, 0, 0};
static bool switchToggle[2] = {false, false};

void setup() {
  Serial.begin(115200);

  Serial2.begin(115200);

  Serial.println("Serial2 Started!");
}

void loop() {
  if(Serial2.available() > STR_SIZE * 5){
    while(Serial2.available()){
      Serial2.read();
    }
  }

  while (Serial2.available() > 0 && Serial2.peek() != '\0') {
    Serial2.read();
  }

  if (Serial2.available() >= 6) {
    Serial2.read();
    
    for(uint8_t i=0; i<4; i++){
      uss[i] = Serial2.read();
    }

    switch(Serial2.read()){
    case 1:
      switchToggle[0] = false;
      switchToggle[1] = false;
      break;
    case 3:
      switchToggle[0] = false;
      switchToggle[1] = true;
      break;
    case 5:
      switchToggle[0] = true;
      switchToggle[1] = false;
      break;
    case 7:
      switchToggle[0] = true;
      switchToggle[1] = true;
      break;
    default:
      switchToggle[0] = false;
      switchToggle[1] = false;
      break;
    }

    Serial.print(switchToggle[0]);
    Serial.print("\t");
    Serial.print(switchToggle[1]);
    Serial.print("\n");
  }


  delay(10);
}
