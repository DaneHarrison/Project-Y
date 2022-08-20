#pragma once
class LED;

class LEDDisplay {
public:
    virtual LEDDisplay* getDisplay() = 0;
    
    virtual void turnOff() = 0;
    virtual void updateLED(int, int, LED) = 0;
    virtual void updateLEDRange(int, int, int, LED) = 0;
    virtual void copyDisplayElement(int, int) = 0;
    virtual void updateDisplay(LEDDisplay*) = 0;
};