// --------------------------------
// Class: LEDStrip
// Author: Dane
//
// Represents an addressible LED Strip (single sequential line of LEDs)
// --------------------------------
#pragma once
#include "../Interfaces/LEDDisplay.h"

class LEDStrip : public LEDDisplay {
private:
    int length;     //Length of the LED strip
    LED ***strip;   //The LED strip's contents

public:
    LEDStrip(int);
    ~LEDStrip();


    // --------------------------------
    // Fetches the current display (getter)
    //
    // Returns:
    // A 2D array of LEDs that make up the current display
    // --------------------------------
    LED ***getDisplay();


    // --------------------------------
    // Turns off the entire display
    // --------------------------------
    void turnOff();


    // --------------------------------
    // Updates individual LEDs 
    //
    // Parameters:
    // posi: the position of the LEDs we'd like to update [0 - length)
    // intVal: unused
    // srcLED: the new LED we'd like to insert into our display
    // --------------------------------
    void updateLEDs(int posi, int intVal, LED *srcLED);
    
    
    // --------------------------------
    // Updates a range of LEDs
    //
    // Parameters:
    // posi: the position of the LEDs we'd like to start updating at [0 - length)
    // intVal: unused
    // num: the number of LEDs we'd like to update
    // srcLED: the new LED we'd like to insert into our display
    // --------------------------------
    void updateLEDRange(int posi, int intVal, int num, LED*);
    
    
    // --------------------------------
    // Copies an individual LED's contents to another
    //
    // Parameters:
    // src: the LED in the display we'd like to copy
    // dest: the LED in the display we'd like to modify
    // --------------------------------
    void copyDisplayElement(int src, int dest);
    
    
    // --------------------------------
    // Overwrites the current display (if sizes and contents are compatible - no nullptrs and same size)
    //
    // height: the height of newDisplay
    // width: the width of newDisplay
    // newDisplay: the input display we'd like to use to update our current display
    // --------------------------------
    void updateDisplay(int height, int width, LED ***newDisplay);
};