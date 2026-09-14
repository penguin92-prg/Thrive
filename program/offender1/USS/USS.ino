void setup() {
  Serial.begin(115200);
  pinMode(D4,OUTPUT);
}

void loop() {
  digitalWrite(D4, LOW);
  delayMicroseconds(2);

  digitalWrite(D4, HIGH);
  delayMicroseconds(10);

  digitalWrite(D4, LOW);

  unsigned long T = pulseIn(D3, HIGH);

  float distance_cm = T / 58.0;

  Serial.println(distance_cm);
  delay(130);
}
