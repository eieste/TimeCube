#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "TCWebserver.h"
#include <LittleFS.h>


void TCWebserver::addEndpoints() {
    server.serveStatic("/static", LittleFS, "/data");


    //First request will return 0 results unless you start scan from somewhere else (loop/setup)
    //Do not request more often than 3-5 seconds
    server.on("/scan", HTTP_GET, [](AsyncWebServerRequest *request){
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


}

void TCWebserver::handleClient() {

}

void TCWebserver::setup(){

    this->addEndpoints();
    server.begin();

}
