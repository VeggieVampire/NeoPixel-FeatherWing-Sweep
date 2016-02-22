#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 15          // Pin for data
#define LEDS 32         // How many LEDs?
#define ROWS 4          // count LEDs downward
#define COLUMS 8        //Count your LEDS to the right
#define SPEED 100       //faster the lower the number

#define RANDLOW 0       //low value for random numbers
#define RANDHIGH 7    //High value for random numbers
long randNumber;
long randNumber2;
long randNumber3;
long randSpeed;


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


    int LetterA[LEDS] = {2,3,9,10,16,18,25,26,27,7};
    int LetterB[LEDS] = {8,1,3,2,10,12,16,18,20,24,25,26,27,7,28}; 
    int LetterC[LEDS] = {0,1,2,3,4,5,6,7,
                         15,23,
                         31,30,29,28,27,26,25,24,
                         16,8,
                         9,10,11,12,13,14,
                         22,21,20,19,18,17
                         }; 

    int LetterC4[LEDS] = {                    
                         17,18,19,20,21,22,
                         14,13,12,11,10,9,
                         8,16,
                         24,25,26,27,28,29,30,31,
                         23,15,
                         7,6,5,4,3,2,1,0
                         }; 

    
//    int LetterA[LEDS] = {2,3,9,10,16,18,25,26,27,7};
void setup() {



  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  
  // Some example procedures showing how to display to the pixels: 
  //random numbers from 1 to 255
  randNumber = random(RANDLOW, RANDHIGH);
  randNumber2 = random(RANDLOW, RANDHIGH);
  randNumber3 = random(RANDLOW, RANDHIGH);
  randSpeed = random(1, 100);

  letterscolorWipe(strip.Color(1, 1, 1), 150); // random color
  colorClear(strip.Color(0, 0, 0), 1);
  letterscolorWipe2(strip.Color(1, 1, 1), 150); // random color
  colorClear(strip.Color(0, 0, 0), 1);
}

// Fills a colums of dots one after the other with a one single color then another color.


void colorClear(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<LEDS; i++) {
  strip.setPixelColor(LetterC[i], 0, 0, 0);
  strip.show();
  delay(10);
    }}

void letterscolorWipe(uint32_t c, uint8_t wait) {
strip.begin();
    for(uint16_t i=0; i<=(LEDS-1); i++) {
      strip.setPixelColor(LetterC[i], 1, random(RANDLOW, RANDHIGH), random(RANDLOW, RANDHIGH));// not part of the code jsut for test
      strip.show();
      delay(15);
      }
}

void letterscolorWipe2(uint32_t c, uint8_t wait) {
strip.begin();
    for(uint16_t i=0; i<=(LEDS-1); i++) {
      strip.setPixelColor(LetterC4[i], 1, 0, random(RANDLOW, RANDHIGH));// not part of the code jsut for test
      strip.show();
      delay(10);
      }
}
