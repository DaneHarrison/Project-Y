#pragma once
#include "../Interfaces/LEDDisplay.h"

class LED {
private:
    int red;
    int green;
    int blue;

public:
    void turnOff();
    void setRed();
    void setGreen();
    void setBlue();
    void setRGB();
    int getRed();
    int getGreen();
    int getBlue();
};