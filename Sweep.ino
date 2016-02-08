#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 15 // Pin for data
#define LEDS 32 // How many LEDs?
#define ROWS 4 // count LEDs downward
#define COLUMS 8 //Count your LEDS to the right
#define SPEED 100 //faster the lower the number

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {



  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(3, 0, 0), SPEED); // Red
  colorWipe(strip.Color(0, 3, 0), SPEED); // Green
  colorWipe(strip.Color(0, 1, 3), SPEED); // Blue
  colorWipe(strip.Color(3, 3, 0), SPEED);
  colorWipe(strip.Color(3, 3, 3), SPEED);
  colorWipe(strip.Color(0, 3, 3), SPEED);
  colorWipe(strip.Color(3, 0, 3), SPEED);


}

// Fills the colums dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<COLUMS; i++) {

    
    strip.setPixelColor(i+(COLUMS*(ROWS-4)),c);

    strip.setPixelColor(i+(COLUMS*(ROWS-3)),c);
    

    
    strip.setPixelColor(i+(COLUMS*(ROWS-2)),c);
    
    
    strip.setPixelColor(i+(COLUMS*(ROWS-1)),c);
    strip.show();
    delay(wait);


  }
}
