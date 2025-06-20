#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <SPI.h>


const int MUX_S0 = 17;
const int MUX_S1 = 4;
const int MUX_S2 = 16;

const int MUX_CS_PIN = 27;
const int MUX_DC_PIN = 32;
const int MUX_RST_PIN = 21;

const int SPI_MOSI = 23; // MOSI Pin
const int SPI_CLK = 18; // CLK Pin



// Nutze den "generischen" Treiber
GxEPD2_BW<GxEPD2_154, GxEPD2_154::HEIGHT> display(GxEPD2_154(MUX_CS_PIN, MUX_DC_PIN, MUX_RST_PIN, 33));


void setup() {




  Log.noticeln("Initializing MUX...");
  pinMode(MUX_S0, OUTPUT);
  pinMode(MUX_S1, OUTPUT);
  pinMode(MUX_S2, OUTPUT);

  digitalWrite(MUX_S0, HIGH);
  digitalWrite(MUX_S1, HIGH);
  digitalWrite(MUX_S2, HIGH);


  Serial.begin(115200);
  delay(1000); // Stabilisierung
  Serial.println("Starte Display");
  display.init(115200);  // langsamer Start hilft manchmal
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(10, 30);
    display.print("ESP32 Test");
  } while (display.nextPage());
}

void loop() {
}