// --------------------------------
// Class: LEDStrip
// Author: Dane
//
// Represents an addressible LED Strip (single sequential line of LEDs)
// --------------------------------
#pragma once
#include "LEDDisplay.h"

class LEDStrip : public LEDDisplay {
private:
    LED **strip;   //The LED strip's contents

public:
    LEDStrip(int height);
    ~LEDStrip();

    void turnOff();

    // --------------------------------
    // Fetches the current display (getter)
    //
    // Returns:
    // A 2D array of LEDs that make up the current display
    // --------------------------------
    LED ***getDisplay();


    // --------------------------------
    // Updates individual LEDs 
    //
    // Parameters:
    // posi: the position of the LEDs we'd like to update [0 - length)
    // intVal: unused
    // num: the position of the LEDs we'd like to update [0 - length)
    // srcLED: the new LED we'd like to insert into our display
    // --------------------------------
    void updateLEDs(int height, int width, int num, LED *srcLED);
    
    
    // --------------------------------
    // Copies an individual LED's contents to another
    //
    // Parameters:
    // src: the LED in the display we'd like to copy
    // dest: the LED in the display we'd like to modify
    // --------------------------------
    void copyDisplayElement(int src, int dest);

    void updateDisplay(int height, int width, LED ***newDisplay);
};