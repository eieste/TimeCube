
#include <WiFi.h>
#include "TCWiFiManager.h"


// Load Wi-Fi library
// Replace with your network credentials
const char* ssid     = "ESP32-Access-Point";
const char* password = "123456789";


TCWiFiManager::TCWiFiManager() {

}

void TCWiFiManager::setup()
{
    // Remove the password parameter, if you want the AP (Access Point) to be open
    WiFi.softAP(ssid, password);

    IPAddress IP = WiFi.softAPIP();
    Log.notice("AP IP address: %s ", IP);
}