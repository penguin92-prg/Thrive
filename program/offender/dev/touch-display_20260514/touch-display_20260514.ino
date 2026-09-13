#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS   3
#define TFT_DC   2
#define TFT_RST  1

#define TFT_SCLK 8
#define TFT_MOSI 10
#define TFT_MISO 9

Adafruit_ILI9341 tft = Adafruit_ILI9341(&SPI, TFT_DC, TFT_CS, TFT_RST);

void setup() {
  Serial.begin(115200);

  SPI.begin(TFT_SCLK, TFT_MISO, TFT_MOSI, TFT_CS);

  tft.begin();

  tft.fillScreen(ILI9341_BLACK);

  tft.setCursor(20, 20);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.println("Hello");
}