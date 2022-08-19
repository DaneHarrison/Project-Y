#pragma once
#include "../Interfaces/LEDDisplay.h"
class LED;

class LEDGrid : public LEDDisplay {
private:
    int rows;
    int cols;
    LED **grid;
    
public:
    LEDGrid();
    void init(int, int);
    
    LEDDisplay* getDisplay();

    void turnOff();
    void updateLED(int, int, LED);
    void updateRow(int, LED);
    void updateRow(int, LEDDisplay*);
    void updateDisplay(LEDDisplay*);
};