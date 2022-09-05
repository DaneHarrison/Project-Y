// --------------------------------
// Class: LEDStrip
// Author: Dane
//
// Represents an addressible LED Strip (single sequential line of LEDs)
// Note: its initialized height must be greater than 0
// --------------------------------
#pragma once
#include "LEDDisplay.h"

class LEDStrip : public LEDDisplay {
private:
    LED **strip;   //The LED strip's contents

public:
    LEDStrip(int height);
    ~LEDStrip();

    // --------------------------------
    // Turns off the entire strip
    // --------------------------------
    void turnOff();

    // --------------------------------
    // Fetches the current display
    //
    // Returns:
    // A 2D array of LEDs that make up the current display
    // --------------------------------
    LED ***getDisplay();

    // --------------------------------
    // Updates individual LEDs 
    //
    // Parameters:
    // xPosi: unused
    // yPosi: the vertical position of the LEDs we'd like to update [0 - length)
    // num: the number of LEDs we'd like to update to match our source [1 - length]
    // srcLED: the LED we'd like to use to update our display
    // --------------------------------
    void updateLEDs(int xPosi, int yPosi, int num, LED *srcLED);
    
    // --------------------------------
    // Copies an individual LED's contents to another
    //
    // Parameters:
    // src: the position of the LED in the display we'd like to copy [0, length)
    // dest: the position of the LED in the display we'd like to amend [0, length)
    // --------------------------------
    void copyDisplayElement(int src, int dest);

    // --------------------------------
    // Overwrites the current display using initialized LEDs.  Note that null values are ignored 
    // and smaller displays can be used to update portions of the display
    //
    // Parameters:
    // height: the height of the new display
    // width: the width of the new display
    // newDisplay: the input display we'd like to use to update our current display
    // --------------------------------
    void updateDisplay(int height, int width, LED ***newDisplay);
};