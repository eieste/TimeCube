#ifndef _TCWIFIMANAGER_H
#define _TCWIFIMANAGER_H


#include <Arduino.h>
#include <Preferences.h>

class TCWiFiManager {
    public:
        TCWiFiManager();
        void setup(Preferences *_prefs);

    private:
        uint16_t _port;
        Preferences *prefs;
};




#endif