#ifndef TC_WEBSERVER_H
#define TC_WEBSERVER_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <Preferences.h>

class TCWebserver {
    public:
        TCWebserver(uint16_t port) : server(port) {};
        void setup(Preferences *_prefs);
        void addEndpoints();
        void handleClient();

    private:
        uint16_t _port;
        AsyncWebServer server;
        Preferences *prefs;

};

#endif // LED_CONTROLLER_H
