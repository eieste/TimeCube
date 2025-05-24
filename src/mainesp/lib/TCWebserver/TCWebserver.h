#ifndef TC_WEBSERVER_H
#define TC_WEBSERVER_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>


class TCWebserver {
    public:
        TCWebserver(uint16_t port) : server(port) {};
        void setup();
        void addEndpoints();
        void handleClient();

    private:
        uint16_t _port;
        AsyncWebServer server;
};

#endif // LED_CONTROLLER_H
