// --------------------------------
// Class: LED
//
// Manages an LED; access and modify its RBG values inside range [0, 255]
// --------------------------------
#pragma once
#include "../Interfaces/LEDDisplay.h"

class LED {
private:
    int red;
    int green;
    int blue;

public:
    static const int MIN_VALUE = 0;     //Lowest valid RGB value (black)
    static const int MAX_VALUE = 255;   //Largest valid RGB value (white)

    LED();

    int getRed();
    int getGreen();
    int getBlue();

    void setRed(int);
    void setGreen(int);
    void setBlue(int);
    void setRGB(int, int, int);
};