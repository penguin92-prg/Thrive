#include <FastLED.h>
#include "esp32_2.hpp"

#define LED_PIN 10
#define NUM_LEDS 16
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

robot::ESP32_2 ESP32_2Board;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  ESP32_2Board.init();
}

void loop() {
  // 赤
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(255, 0, 0);
  }
  FastLED.show();
  delay(500);

  // 青
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 255);
  }
  FastLED.show();
  delay(500);

  // 消灯
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(500);
}
