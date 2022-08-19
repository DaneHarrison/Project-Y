#pragma once
#include "../Interfaces/LEDDisplay.h"
class LED;

class LEDStrip : public LEDDisplay {
private:
    int length;
    LED *leds[];

public:
    LEDStrip();
    void init(int, int);

    LEDDisplay* getDisplay();

    void turnOff();
    void updateLED(int, int, LED);
    void updateLEDSRange(int, int, LED);
    void updateDisplay(LEDDisplay*);
};