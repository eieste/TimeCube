
#include <WiFi.h>
#include "TCWiFiManager.h"
#include <Preferences.h>
#include <ArduinoLog.h>


TCWiFiManager::TCWiFiManager() {
}

void TCWiFiManager::setup(Preferences *_prefs)
{
    prefs = _prefs;
    prefs->begin("network", true); // true = readOnly
    if(prefs->getString("wifi_mode", "ap") == "ap") {
        Log.noticeln("Setting up WiFi in AP mode");
        WiFi.softAP(prefs->getString("wifi_ap_ssid", "TimeCube").c_str(), prefs->getString("wifi_ap_password", "12345678").c_str());
        IPAddress IP = WiFi.softAPIP();
        Log.noticeln("AP IP address: %s ", IP.toString().c_str());
    } else if(prefs->getString("wifi_mode", "ap") == "sta") {
        Log.noticeln("Setting up WiFi in STA mode");
        WiFi.begin(prefs->getString("wifi_sta_ssid", "").c_str(),
                   prefs->getString("wifi_sta_password", "").c_str());
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Log.noticeln(".");
        }
        Log.noticeln("Connected to WiFi, IP address: %s ", WiFi.localIP().toString().c_str());
    } else {
        Log.noticeln("Setting up WiFi in STA mode");
    }
}