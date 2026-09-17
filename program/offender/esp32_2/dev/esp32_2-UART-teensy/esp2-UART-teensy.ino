constexpr uint8_t USS_1_PIN = D0;
constexpr uint8_t USS_2_PIN = D1;
constexpr uint8_t USS_3_PIN = D2;
constexpr uint8_t USS_4_PIN = D3;
constexpr uint8_t USS_EN_PIN = D4;

constexpr uint8_t SW_TOGGLE_1_PIN = D5;
constexpr uint8_t SW_TOGGLE_2_PIN = D8;

void setup() {
  pinMode(USS_EN_PIN, OUTPUT);

  pinMode(SW_TOGGLE_1_PIN, INPUT);
  pinMode(SW_TOGGLE_2_PIN, INPUT);

  Serial.begin(115200);

  // Serial1.setPins(RX, TX);
  Serial1.setPins(D7, D6);
  Serial1.begin(115200);

  Serial.println("Serial1 Started!");
}

void loop() {
  uint8_t send[6];
  send[0] = (1);
  send[1] = (1);
  send[2] = (1);
  send[3] = (1);
  send[4] = (((digitalRead(SW_TOGGLE_1_PIN) << 2) | (digitalRead(SW_TOGGLE_2_PIN) << 1)) & 0b11111110) + 1;
  send[5] = '\0'; // 終端パケット

  for (auto &buf : send) {
    Serial1.write(buf);
    Serial.print(buf);
    Serial.print("\t");
  }
  Serial.print("\n");

  // Serial.print(digitalRead(SW_TOGGLE_1_PIN));
  // Serial.print("\t");
  // Serial.print(digitalRead(SW_TOGGLE_2_PIN));
  // Serial.print("\t");
  // Serial.print(send[4]);
  // Serial.print("\n");

  delay(10);
}
