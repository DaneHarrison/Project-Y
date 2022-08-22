// --------------------------------
// Class: FillLilacPattern
// Author: Dane
//
// Creates a solid Lilac colored display using the strategy pattern
// --------------------------------
#pragma once
#include "../Interfaces/PatternStrategy.h"

class FillLilacPattern : public PatternStrategy {
private:
    LED *lilacLED;  //Represents an instance of the Lilac LED this strategy uses

public:
    FillLilacPattern();

    // --------------------------------
    // Generates a static lilac colored display
    //
    // Parameters:
    // height: the height of the display
    // width: the width of the display
    // frequency: the calculated audio frequency (not used)
    // display: represents the display being modified - its type and contents (not used)
    //
    // Returns:
    // A 2D array of LEDs that make up the current display
    // --------------------------------
    LED ***usePattern(int height, int width, int frequency, LEDDisplay* display);
};