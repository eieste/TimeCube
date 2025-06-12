#include <Adafruit_NeoPixel.h>

const uint8_t ledsPerStripe = 7;
const uint8_t numStripes = 12;

// Pins für die 12 LED-Stripes
const uint8_t stripePins[numStripes] = {17,16,13,0,1,3,2,4,5,6,7,8};
 //{0,1,2,3,4,5,6,7,8,9,10,11};
// Eine Instanz pro Stripe
Adafruit_NeoPixel* stripes[numStripes];

const int colors[12][3] = {
    {255, 0, 0},     // Rot
    {0, 255, 0},     // Grün
    {0, 0, 255},     // Blau
    {255, 255, 0},   // Gelb
    {0, 255, 255},   // Cyan
    {255, 0, 255},   // Magenta
    {255, 165, 0},   // Orange
    {128, 0, 128},   // Violett
    {0, 128, 128},   // Türkis
    {192, 192, 192}, // Hellgrau
    {128, 128, 0},   // Oliv
    {255, 105, 180}  // Pink
};

void setup() {
  for (uint8_t i = 0; i < numStripes; i++) {
    stripes[i] = new Adafruit_NeoPixel(ledsPerStripe + 1, stripePins[i], NEO_GRB + NEO_KHZ800); // +1 für die Start-LED
    stripes[i]->begin();
    stripes[i]->show(); // Initialisieren
  }
}

void loop() {
  for (uint8_t y = 0; y < numStripes; y++) {
    stripes[y]->clear();  // Alle LEDs aus


    int number = stripePins[y]+1;  // z. B. 2 bis 26

    for (int i = 0; i < ledsPerStripe; i++) {
      bool bit = (number >> i) & 0x01;
      if (bit) {
        stripes[y]->setPixelColor(i + 1, colors[y][0], colors[y][1], colors[y][2]);
      } else {
        stripes[y]->setPixelColor(i + 1, 0, 0, 0); // aus
      }
    }

    // Erste LED (Index 0) wird immer auf weiß gesetzt
    stripes[y]->setPixelColor(0, 255, 255, 255);
    stripes[y]->show();
    delay(10);
  }

  delay(10);
}