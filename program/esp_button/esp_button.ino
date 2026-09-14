void setup() {
  pinMode(D8,INPUT);
  pinMode(D10,INPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.print(digitalRead(D8));
  Serial.print(" ");
  Serial.print(digitalRead(D10));
  Serial.println(); 
}
