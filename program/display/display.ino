#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  pinMode(D8,INPUT);
  pinMode(D10,INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 disconnection"));
    for(;;); 
  }
  display.clearDisplay(); //初期化

}

int c = 0;

void loop() {
  if(digital.read)
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(48,32);
  display.println("370");
  display.display();
}