#pragma once
class LED;

#include "../Interfaces/LEDDisplay.h"

class LEDStrip : public LEDDisplay {
private:
    int length;
    LED *leds[];

public:
    LEDStrip(int);

    LEDDisplay* getDisplay();

    void turnOff(); //sets all LEDs to 0
    void updateLED(int, int, LED); //updates an individually spec /lED
    void updateLEDRange(int, int, int, LED); //updates a range of LEDs x, start y, enf y
    void copyDisplayElement(int, int); //copies an LED element to another LED
    void updateDisplay(LEDDisplay*); //Lets you completley override
};