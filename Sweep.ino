#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 15 // Pin for data
#define LEDS 32 // How many LEDs?
#define ROWS 4 // count LEDs downward
#define COLUMS 8 //Count your LEDS to the right
#define SPEED 100 //faster the lower the number

long randNumber;
long randNumber2;
long randNumber3;

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
  //random numbers from 1 to 255
  randNumber = random(1, 255);
  randNumber2 = random(1, 255);
  randNumber3 = random(1, 255);
  colorWipe(strip.Color(randNumber, randNumber2, randNumber3), SPEED); // random color



}

// Fills a colums of dots one after the other with a one single color then another color.
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<COLUMS; i++) {

    for (uint16_t r=(-ROWS); r> (ROWS); r--){
      strip.setPixelColor(i+(COLUMS*(ROWS-r)),c);
    }
    strip.show();
    delay(wait);
  }
}
