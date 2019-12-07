#include "Throttle.h"

Throttle::Throttle():
    previousDuration(0),
    isRisen(false),
    isFallen(false),
    debounceTimeMillis(50),
    lastChangedTime(0),
    previousPressedState(0),
    pin(0) {}

    Throttle::Throttle(int pin):
    previousDuration(0),
    isRisen(false),
    isFallen(false),
    debounceTimeMillis(50),
    lastChangedTime(0),
    previousPressedState(0),
    pin(pin) {
        attach(pin);
    }

    Throttle::Throttle(int pin, int mode):
    previousDuration(0),
    isRisen(false),
    isFallen(false),
    debounceTimeMillis(50),
    lastChangedTime(0),
    previousPressedState(0),
    pin(pin) {
        attach(pin, mode);
    }

    Throttle::Throttle(int pin, int mode, uint16_t interval_millis):
    previousDuration(0),
    isRisen(false),
    isFallen(false),
    debounceTimeMillis(50),
    lastChangedTime(0),
    previousPressedState(0),
    pin(pin) {
        attach(pin, mode);
        interval(interval_millis);
    }

void Throttle::attach(int pin) {
    this->pin = pin;
    previousPressedState = 0;
}

void Throttle::attach(int pin, int mode) {
    pinMode(pin, mode);
    this->attach(pin);
}

void Throttle::interval(uint16_t debounceTimeMillis) {
    this->debounceTimeMillis = debounceTimeMillis;
}

bool Throttle::fell() {
    return isFallen;
}

bool Throttle::rose() {
    return isRisen;
}

bool Throttle::changed() {
    return fell() || rose();
}

bool Throttle::read() {
    return previousPressedState;
}

unsigned long Throttle::duration() {
    return previousDuration;
}

bool Throttle::update() {
    isRisen = false;
    isFallen = false;
    unsigned long currentTime = millis();
    if (currentTime - lastChangedTime > debounceTimeMillis)
    {
      bool isPressedState = digitalRead(pin);

      if (isPressedState == previousPressedState)
        return false;

      if(isPressedState) {
          isRisen = true;
      } else {
        isFallen = true;
      }
      
      previousDuration = currentTime - lastChangedTime;
      lastChangedTime = currentTime;
      previousPressedState = isPressedState;
      return true;
    } 
    return false;
}