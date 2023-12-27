#include <FastLED.h>

#define LED_PIN     6         // Define the pin where the data line is connected
#define NUM_LEDS    290       // Define the number of LEDs in the strip

CRGB leds[NUM_LEDS];          // Define the LED array

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);  // Initialize the FastLED library
  FastLED.setBrightness(50);                               // Adjust brightness (0-255)
}

void loop() {
  rainbowEffect();
}

void rainbowEffect() {
  static uint8_t hue = 0;

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + i, 255, 255);
  }

  FastLED.show();
  FastLED.delay(20);  // Adjust the delay to control the speed of the rainbow effect

  hue++;  // Increment the hue for next iteration
}
