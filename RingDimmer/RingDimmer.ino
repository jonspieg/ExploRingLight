#include <Adafruit_NeoPixel.h>

  int numLeds = 24;
  int potPin = A0;
  int ledPin = 4;
  int overallBrightness = 255;
  int oldBrightness = 0;
  int brightness = 0;
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, ledPin, NEO_GRBW + NEO_KHZ800);
  
void setup() {
  strip.setBrightness(overallBrightness);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  oldBrightness = brightness;
  brightness = map(analogRead(potPin), 0, 1023, 20, 255);
  if(brightness != oldBrightness)
  {
    for(int i=0;i<strip.numPixels();i++)
    {
      strip.setPixelColor(i, strip.Color(0, 0, 0, brightness));
    }
    strip.show();
  }
}
