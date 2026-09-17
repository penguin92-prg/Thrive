void setup() {
  pinMode(D5, INPUT);
  pinMode(D8, INPUT);

  Serial.begin(115200);
}

void loop() {
  Serial.print(digitalRead(D5));
  Serial.print("\t");
  Serial.println(digitalRead(D8));
  delay(50);
}