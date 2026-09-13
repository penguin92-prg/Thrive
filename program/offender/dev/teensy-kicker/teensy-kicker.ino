void setup() {
  pinMode(31, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  digitalWrite(31, HIGH);
  Serial.println("Kicked!");
  delay(5000);
  digitalWrite(31, LOW);
  delay(5000);
}