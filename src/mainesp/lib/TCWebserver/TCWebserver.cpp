#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "TCWebserver.h"
#include <LittleFS.h>
#include <Preferences.h>


void TCWebserver::addEndpoints() {
    server.serveStatic("/", LittleFS, "/web").setDefaultFile("index.html");

    //First request will return 0 results unless you start scan from somewhere else (loop/setup)
    //Do not request more often than 3-5 seconds
    server.on("/api/v1/wifi/scan", HTTP_GET, [](AsyncWebServerRequest *request){
        String json = "[";
        int n = WiFi.scanComplete();
        if(n == -2){
            WiFi.scanNetworks(true);
        } else if(n){
            for (int i = 0; i < n; ++i){
            if(i) json += ",";
            json += "{";
            json += "\"rssi\":"+String(WiFi.RSSI(i));
            json += ",\"ssid\":\""+WiFi.SSID(i)+"\"";
            json += ",\"bssid\":\""+WiFi.BSSIDstr(i)+"\"";
            json += ",\"channel\":"+String(WiFi.channel(i));
            json += ",\"secure\":"+String(WiFi.encryptionType(i));
            //json += ",\"hidden\":"+String(WiFi.isHidden(i)?"true":"false");
            json += "}";
            }
            WiFi.scanDelete();
            if(WiFi.scanComplete() == -2){
            WiFi.scanNetworks(true);
            }
        }
        json += "]";
        request->send(200, "application/json", json);
        json = String();
    });

    server.on("/api/v1/network", HTTP_GET, [](AsyncWebServerRequest *request){
        String json = "{";
        json += "\"ip\":\"" + WiFi.localIP().toString() + "\"";
        json += ",\"mac\":\"" + WiFi.macAddress() + "\"";
        json += ",\"gateway\":\"" + WiFi.gatewayIP().toString() + "\"";
        json += ",\"subnet\":\"" + WiFi.subnetMask().toString() + "\"";
        json += ",\"dns\":\"" + WiFi.dnsIP().toString() + "\"";
        json += ",\"ssid\":\"" + WiFi.SSID() + "\"";
        json += ",\"rssi\":" + String(WiFi.RSSI());
        json += ",\"status\":\"" + String(WiFi.status() == WL_CONNECTED ? "connected" : "disconnected") + "\"";
        json += "}";
        request->send(200, "application/json", json);
    });


}

void TCWebserver::handleClient() {

}

void TCWebserver::setup(Preferences *_prefs){

    prefs = _prefs;
    prefs->begin("network", false); // true = readOnly

//    String ssid = prefs.getString("ssid", "");
//    prefs.end();



    this->addEndpoints();
    server.begin();

}
