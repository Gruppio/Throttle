# Throttle
Throttle library for arduino, just like a debounce but faster!

## Advantages
There are already some libraries that perform some functionalities like `Throttle`.
One of the most famous is `Bounce`, the problem is if that the output of bounce is delayed
and if you have to press a button multiple times very frequently is unereliable.
With `Throttle` you will not have any issue 😎

## Compatibility
The `Throttle` object has the same interface of the `Bounce` so you can just replace the instantiation and compile!

## Example
```c
// This example toggles the debug LED (pin 13) on or off
// when a button on pin 2 is pressed.

// Include the Throttle library found here :
// https://github.com/Gruppio/Throttle

#include <Arduino.h>
#include <Throttle.h>

#define BUTTON_PIN 2
#define LED_PIN 13

Throttle button = Throttle(BUTTON_PIN, INPUT_PULLUP);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState);
}

void loop() {
   button.update();
   
   if (button.fell()) {
     ledState = !ledState;
     digitalWrite(LED_PIN, ledState);
   }
}
```

## If you like this project please:

<a href="https://www.buymeacoffee.com/gruppio" target="_blank"><img src="https://raw.githubusercontent.com/Gruppio/Sonoff-Homekit/images/images/buymeacoffee.png" alt="Buy Me A Coffee" width="300" ></a>

## Thank you!
