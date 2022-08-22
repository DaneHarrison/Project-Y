// --------------------------------
// Class: LEDGrid
// Author: Dane
//
// Represents an addressible LED Grid (height x width)
// --------------------------------
#pragma once
#include "../Interfaces/LEDDisplay.h"

class LEDGrid : public LEDDisplay {
private:
    int rows;       //The height of the display
    int cols;       //The width of the display
    LED ***grid;    //The LED grid's contents
    
public:
    LEDGrid(int, int);
    ~LEDGrid();


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
    // Updates speicifed LEDs, if a width of -1 is given a single LED is replaced otherwise 
    // the entire row is replaced by the source
    //
    // Parameters:
    // height: the height of the LEDs we'd like to update
    // width: the width of the LEDs we'd like to update
    // srcLED: the new LED we'd like to insert into our display
    // --------------------------------
    void updateLEDs(int height, int width, LED *srcLED);


    // --------------------------------
    // Updates a range of LEDs
    //
    // Parameters:
    // height: the height of the LEDs we'd like to start updating at
    // width: the width of the LEDs we'd like to update
    // num: the number of LEDs we'd like to update
    // srcLED: the new LED we'd like to insert into our display
    // --------------------------------
    void updateLEDRange(int height, int width, int num, LED *srcLED);


    // --------------------------------
    // Copies a row of LED contents to another
    //
    // Parameters:
    // src: the row in the display we'd like to copy
    // dest: the row in the display we'd like to modify
    // --------------------------------
    void copyDisplayElement(int src, int dest);


    // --------------------------------
    // Overwrites the current display (if sizes and contents are compatible - no nullptrs and same size)
    //
    // Parameters:
    // height: the height of newDisplay
    // width: the width of newDisplay
    // newDisplay: the input display we'd like to use to update our current display
    // --------------------------------
    void updateDisplay(int height, int width, LED ***newDisplay);
};