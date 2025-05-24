#include "LedController.h"

LedController::LedController(uint8_t pin) : _pin(pin), _state(false) {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void LedController::on() {
    digitalWrite(_pin, HIGH);
    _state = true;
}

void LedController::off() {
    digitalWrite(_pin, LOW);
    _state = false;
}

void LedController::toggle() {
    if (_state) {
        off();
    } else {
        on();
    }
}

bool LedController::isOn() const {
    return _state;
}
