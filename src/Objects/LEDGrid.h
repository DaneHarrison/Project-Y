// --------------------------------
// Class: LEDGrid
// Author: Dane
//
// Represents an addressible LED Grid
// Note: its initialized height and width must both be greater than 0
// --------------------------------
#pragma once
#include "LEDDisplay.h"

class LEDGrid : public LEDDisplay {
private:
    LEDStrip **grid;    //The LED grid's contents
    
public:
    LEDGrid(int height, int width);
    ~LEDGrid();

    // --------------------------------
    // Turns off the entire grid
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
    // Updates individual LEDs (vertically) 
    //
    // Parameters:
    // xPosi: the horizontal position of the LEDs we'd like to update [0 - length)
    // yPosi: the vertical position of the LEDs we'd like to update [0 - length)
    // num: the number of LEDs we'd like to update to match our source [1 - length]
    // srcLED: the LED we'd like to use to update our display
    // --------------------------------
    void updateLEDs(int xPosi, int yPosi, int num, LED *srcLED);

    // --------------------------------
    // Copies a row of LEDs to another
    //
    // Parameters:
    // src: the position of the LED row in the display we'd like to copy [0, length)
    // dest: the position of the LED row in the display we'd like to amend [0, length)
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

    // --------------------------------
    // Returns a LEDStrip from the grid.  Note changes made to the returned strip
    // will update the grid
    //
    // Parameters:
    // posi: the LEDStrip we'd like to access and modify
    //
    // Returns:
    // An LEDStrip corresponding to the vertical strip from the grid we'd like to modify
    // --------------------------------
    LEDStrip *getStrip(int posi);
};