#pragma once
class LED;

class LEDDisplay {
public:
    virtual LED ***getDisplay() = 0;
    
    virtual void turnOff() = 0;
    virtual void updateLEDs(int, int, LED*) = 0;
    virtual void updateLEDRange(int, int, int, LED*) = 0;
    virtual void copyDisplayElement(int, int) = 0;
    virtual void updateDisplay(int, int, LED***) = 0;
};