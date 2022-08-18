#pragma once
#include "../Interfaces/LEDDisplay.h"
//#include "LED.h"

class LEDStrip : public LEDDisplay {
private:
    //LED leds[];

public:
    LEDStrip(int);
    void turnOff();
    void updateDisplay(LEDDisplay*);
    LEDDisplay* getDisplay();
};