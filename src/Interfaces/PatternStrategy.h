// --------------------------------
// Class: PatternStrategy
// Author: Dane
// 
// An abstract strategy used to generate a new display based on audio frequency
// --------------------------------
#pragma once
class LEDDisplay;
class LED;

class PatternStrategy {
public:
    // --------------------------------
    // Generates a new display based on audio frequency
    //
    // Parameters:
    // height: the height of the display
    // width: the width of the display
    // frequency: the calculated audio frequency
    // display: represents the display being modified - its type and contents
    //
    // Returns:
    // A 2D array of LEDs that make up the current display
    // --------------------------------
    virtual LED ***usePattern(int height, int width, int frequency, LEDDisplay *display) = 0;
};