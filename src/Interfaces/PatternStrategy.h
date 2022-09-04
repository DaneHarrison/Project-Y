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
    // frequency: the calculated audio frequency
    // display: represents the display being modified - its type and contents
    //
    // Returns:
    // A 2D array of LEDs that make up the current display
    // --------------------------------
    virtual LED ***usePattern(int frequency, LEDDisplay *display) = 0;
};