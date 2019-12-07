#include "Throttle.h"

Throttle::Throttle():
    previousDuration(0),
    isRisen(false),
    isFallen(false),
    debounceTimeMillis(0),
    lastChangedTime(0),
    previousPressedState(0),
    pin(0) {}

void Throttle::attach(int pin) {
    this->pin = pin;
    previousPressedState = 0;
}

void Throttle::attach(int pin, int mode) {
    setPinMode(pin, mode);
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
          isFallen = true;
      } else {
        isRisen = true;
      }
      
      previousDuration = currentTime - lastChangedTime;
      lastChangedTime = currentTime;
      previousPressedState = isPressedState;
      return true;
    } 
    return false;
}

unsigned long Bounce::duration() {
	return (millis() - stateChangeLastTime);
}