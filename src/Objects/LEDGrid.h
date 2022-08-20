#pragma once
class LED;

#include "../Interfaces/LEDDisplay.h"

class LEDGrid : public LEDDisplay {
private:
    int rows;
    int cols;
    LED ***grid;
    
public:
    LEDGrid(int, int);
    ~LEDGrid();

    LED ***getDisplay();

    void turnOff();
    void updateLEDs(int, int, LED*);
    void updateLEDRange(int, int, int, LED*);
    void copyDisplayElement(int, int);
    void updateDisplay(int, int, LED***);
};