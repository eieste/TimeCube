#include <Wire.h>
#include <ArduinoLog.h>
#include <LittleFS.h>
#include "TCWebserver.h"
#include "TCWiFiManager.h"
#include <Preferences.h>
#include <GxEPD2_BW.h>
#include <SPI.h>

TCWebserver tcws(80);
TCWiFiManager wifi;
Preferences prefs;

int AN_POT;
const int MUX_S0 = 17;
const int MUX_S1 = 4;
const int MUX_S2 = 16;

const int MUX_CS_PIN = 27;
const int MUX_DC_PIN = 32;
const int MUX_RST_PIN = 21;

const int SPI_MOSI = 23; // MOSI Pin
const int SPI_CLK = 18; // CLK Pin

int count = 4; // Counter for MUX selection

GxEPD2_BW<GxEPD2_154, GxEPD2_154::HEIGHT> *currentDisplay = nullptr;

GxEPD2_BW<GxEPD2_154, GxEPD2_154::HEIGHT> display1(GxEPD2_154(MUX_CS_PIN, MUX_DC_PIN, MUX_RST_PIN, 26));
GxEPD2_BW<GxEPD2_154, GxEPD2_154::HEIGHT> display2(GxEPD2_154(MUX_CS_PIN, MUX_DC_PIN, MUX_RST_PIN, 39));
GxEPD2_BW<GxEPD2_154, GxEPD2_154::HEIGHT> display3(GxEPD2_154(MUX_CS_PIN, MUX_DC_PIN, MUX_RST_PIN, 33));
GxEPD2_BW<GxEPD2_154, GxEPD2_154::HEIGHT> display4(GxEPD2_154(MUX_CS_PIN, MUX_DC_PIN, MUX_RST_PIN, 34));
GxEPD2_BW<GxEPD2_154, GxEPD2_154::HEIGHT> display5(GxEPD2_154(MUX_CS_PIN, MUX_DC_PIN, MUX_RST_PIN, 35));

bool filesystemOK = false;
byte RxByte;

void I2C_RxHandler(int numBytes)
{
  while(Wire.available()) {  // Read Any Received Data
    RxByte = Wire.read();
  }
}

void InitFilesystem() {
  // Initialize LittleFS
  if (!LittleFS.begin(false /* false: Do not format if mount failed */)) {
    Serial.println("Failed to mount LittleFS");
    if (!LittleFS.begin(true /* true: format */)) {
      Serial.println("Failed to format LittleFS");
    } else {
      Serial.println("LittleFS formatted successfully");
      filesystemOK = true;
    }
  } else { // Initial mount success
    filesystemOK = true;
  }
}

void initialize(){
  prefs.begin("bootup",false);
  const bool init = prefs.getBool("initialized", false);

  if(!init) {
    Log.noticeln("Preferences already initialized.");
    prefs.clear();
    prefs.putBool("initialized", true);
  }
  prefs.end();

  if(!init){
    prefs.begin("network", false);
    prefs.clear();
    prefs.putString("wifi_ap_ssid", "TimeCube");
    prefs.putString("wifi_ap_password", "12345678");
    prefs.putString("wifi_mode", "ap");
    prefs.end();
  }
}

void setup() {
  SPI.begin(SPI_CLK, -1, SPI_MOSI); // CLK, MISO (nicht benötigt), MOSI
  Serial.begin(115200); 
  Log.begin(LOG_LEVEL_VERBOSE, &Serial); // Maximaler Detailgrad
  InitFilesystem();
  
  Log.noticeln("Wifi Start");
  wifi.setup(&prefs);
  Log.noticeln("Webserver Start");
  tcws.setup(&prefs);

  Log.noticeln("Initializing MUX...");
  pinMode(MUX_S0, OUTPUT);
  pinMode(MUX_S1, OUTPUT);
  pinMode(MUX_S2, OUTPUT);

  pinMode(MUX_DC_PIN, OUTPUT);
  pinMode(MUX_RST_PIN, OUTPUT);
  pinMode(MUX_CS_PIN, OUTPUT);


display1.init(115200, true, 2, false);

  Log.noticeln("Setup END");
}
 
void loop() {
  tcws.handleClient();

  count = 4;
  Log.noticeln("Mux %d", count);
  digitalWrite(MUX_S0, (count >> 0) & 0x01);
  digitalWrite(MUX_S1, (count >> 1) & 0x01);
  digitalWrite(MUX_S2, (count >> 2) & 0x01);

  if (count == 4) {
    Log.noticeln("Use Display1");
    currentDisplay = &display1;
  } else if (count == 6) {
    Log.noticeln("Use Display2");
    currentDisplay = &display2;
  } else if (count == 7) {
    Log.noticeln("Use Display3");
    currentDisplay = &display3;
  } else if (count == 3) {
    Log.noticeln("Use Display4");
    currentDisplay = &display4;
  } else if (count == 0) {
    Log.noticeln("Use Display5");
    currentDisplay = &display5;
  }

  if(currentDisplay == nullptr) {
    Log.errorln("No display selected for current MUX selection: %d", count);
  }else{
    do
    {
      currentDisplay->fillScreen(GxEPD_WHITE);
      currentDisplay->setCursor(10, 10);
      currentDisplay->print("HelloWorld");
    }
    while (currentDisplay->nextPage());
  }

  count++;

  if (count >= 8) {
    count = 0;
  }

  currentDisplay = nullptr; // Reset currentDisplay to avoid using it again in this loop
  delay(10000);
}