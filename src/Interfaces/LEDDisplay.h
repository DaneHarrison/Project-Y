#pragma once

class LEDDisplay {
public:
    virtual void turnOff() = 0;
    virtual LEDDisplay* getDisplay() = 0;
    virtual void updateDisplay(LEDDisplay*) = 0;
};