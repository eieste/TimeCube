#ifndef _TCWIFIMANAGER_H
#define _TCWIFIMANAGER_H


#include <Arduino.h>


class TCWiFiManager {
    public:
        TCWiFiManager();
        void setup();

    private:
        uint16_t _port;
};




#endif