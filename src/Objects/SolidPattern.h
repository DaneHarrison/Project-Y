// --------------------------------
// Class: SolidPattern
// Author: Dane
//
// Creates a solid colored display using the strategy pattern (according to RGB values)
// Note: by default the solidPattern is set to lilac
// --------------------------------
#pragma once
#include "../Interfaces/PatternStrategy.h"

class SolidPattern : public PatternStrategy {
private:
    LED *fill;  //The LED used to fill the display
    int red;    //Represents the red value of the solid color
    int green;  //Represents the green value of the solid color
    int blue;   //Represents the blue value of the solid color 

public:
    SolidPattern(int red = 206, int green = 162, int blue = 253);

    // --------------------------------
    // Generates a solid colored display based on the constants RED, GREEN and BLUE
    //
    // Parameters:
    // frequency: unused
    // display: represents the display being modified - its type and contents
    //
    // Returns:
    // A 2D array of LEDs that make up the current display
    // --------------------------------
    LED ***usePattern(int frequency, LEDDisplay* display);
};