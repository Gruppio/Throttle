#ifndef THROTTLE_H
#define THROTTLE_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

class Throttle {
public:
    Throttle();
    Throttle(int pin);
    Throttle(int pin, int mode);
    Throttle(int pin, int mode, uint16_t interval_millis);
    void attach(int pin);
    void attach(int pin, int mode);
    void interval(uint16_t interval_millis);
    bool update();
    bool fell();
    bool rose();
    bool changed();
    bool read();
    unsigned long duration();

protected:
    unsigned long previousDuration;
    bool isRisen;
    bool isFallen;
    uint16_t debounceTimeMillis;
    unsigned long lastChangedTime;
    uint8_t previousPressedState;
    uint8_t pin;
};

#endif
