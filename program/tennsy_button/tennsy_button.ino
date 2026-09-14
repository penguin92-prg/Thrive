void setup() {
  pinMode(5,INPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.println(digitalRead(5));  
}
