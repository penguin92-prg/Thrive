constexpr KICKER_STROKE_PIN = 30;
constexpr KICKER_CHIP_PIN = 31;

void setup() {
  pinMode(KICKER_STROKE_PIN, OUTPUT);
  pinMode(KICKER_CHIP_PIN, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  digitalWrite(KICKER_STROKE_PIN, HIGH);
  digitalWrite(KICKER_CHIP_PIN, HIGH);
  Serial.println("Kick Start!");
  delay(50);
  digitalWrite(KICKER_STROKE_PIN, LOW);
  digitalWrite(KICKER_CHIP_PIN, LOW);
  Serial.println("Kick Stop!");
  delay(5000);
}