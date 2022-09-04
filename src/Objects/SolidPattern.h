// --------------------------------
// Class: SolidPattern
// Author: Dane
//
// Creates a solid colored display using the strategy pattern (according to RGB values)
// --------------------------------
#pragma once
#include "../Interfaces/PatternStrategy.h"

class SolidPattern : public PatternStrategy {
private:
    const int RED = 206;    //Represents the red value of the solid color
    const int GREEN = 162;  //Represents the green value of the solid color
    const int BLUE = 253;   //Represents the blue value of the solid color

public:
    // --------------------------------
    // Generates a solid colored display based on the constants RED, GREEN and BLUE
    //
    // Parameters:
    // frequency: the calculated audio frequency (not used)
    // display: represents the display being modified - its type and contents (not used)
    //
    // Returns:
    // A 2D array of LEDs that make up the current display
    // --------------------------------
    LED ***usePattern(int frequency, LEDDisplay* display);
};