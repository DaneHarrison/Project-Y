#pragma once
#include "../Interfaces/LEDDisplay.h"

class LEDGrid : public LEDDisplay {
private:
    //matrix of size n by m
    
public:
    LEDGrid();
    LEDGrid(int, int);
    void turnOff();
    void updateDisplay(LEDDisplay*);
    LEDDisplay* getDisplay();
};