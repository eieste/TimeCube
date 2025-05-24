#include <Wire.h>
#include <ArduinoLog.h>
#include <LittleFS.h>
#include "TCWebserver.h"
#include "TCWiFiManager.h"


TCWebserver tcws(80);
TCWiFiManager wifi;

int AN_POT;

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

void setup() {
  Serial.begin(9600); 
  Log.begin(LOG_LEVEL_VERBOSE, &Serial); // Maximaler Detailgrad
  Log.notice("HIIIIII")
  InitFilesystem();
  Log.notice("Wifi Start");
  wifi.setup();
  Log.notice("Webserver Start");
  tcws.setup();
}
 
void loop() {
  tcws.handleClient();
  //Wire.beginTransmission(0x55); // Transmit to device with address 85 (0x55)
  //Wire.write(5);      // Sends Potentiometer Reading (8Bit)
  //Wire.endTransmission();       // Stop transmitting
  delay(100);
}