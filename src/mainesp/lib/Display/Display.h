#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <Arduino.h>

class LedController {
public:
    LedController(uint8_t pin);
    void on();
    void off();
    void toggle();
    bool isOn() const;

private:
    uint8_t _pin;
    bool _state;
};

#endif // LED_CONTROLLER_H
