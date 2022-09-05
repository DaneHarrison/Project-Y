// --------------------------------
// Class: LEDDisplay
// Author: Dane
//
// Represents an abstract addressible LED Display
// --------------------------------
#pragma once
class LEDStrip;
class LED;

class LEDDisplay {
private:
    int height; //the height of the display
    int width;  //the width of the display

public:
    LEDDisplay(int height, int width);

    // --------------------------------
    // Fetches the display's height
    //
    // Returns:
    // An integer that refers to the displays height
    // --------------------------------
    virtual int getHeight();

    // --------------------------------
    // Fetches the current width
    //
    // Returns:
    // An integer that refers to the displays width
    // --------------------------------
    virtual int getWidth();

    // --------------------------------
    // Turns off the display
    // --------------------------------
    virtual void turnOff() = 0;

    // --------------------------------
    // Fetches the current display
    //
    // Returns:
    // A copy of the 2D array of LEDs that make up the current display
    // --------------------------------
    virtual LED ***getDisplay() = 0;

    // --------------------------------
    // Updates a range of LEDs
    //
    // Parameters:
    // xPosi: the horizontal position of the LEDs we'd like to update [0 - length)
    // yPosi: the vertical position of the LEDs we'd like to update [0 - length)
    // num: the number of LEDs we'd like to update to match our source [1 - length]
    // srcLED: the LED we'd like to use to update our display
    // --------------------------------
    virtual void updateLEDs(int xPosi, int yPosi, int num, LED *srcLED) = 0;

    // --------------------------------
    // Copies a portion of the display's contents to another portion
    //
    // Parameters:
    // src: the location in the display we'd like to copy
    // dest: the location in the display we'd like to amend
    // --------------------------------
    virtual void copyDisplayElement(int src, int dest) = 0;
    
    // --------------------------------
    // Overwrites the current display using initialized LEDs.  Note that null values are ignored 
    // and smaller displays can be used to update portions of the display
    //
    // Parameters:
    // height: the height of the new display
    // width: the width of the new display
    // newDisplay: the input display we'd like to use to update our current display
    // --------------------------------
    virtual void updateDisplay(int height, int width, LED ***newDisplay) = 0;
    
    // --------------------------------
    // Validates a position in the display 
    //
    // Parameters:
    // posi: the position we'd like to check
    // checkWidth: determines whether we are checking against the width or height (checks height by default)
    //
    // Returns:
    // A boolean representing whether if the checked position was valid
    // --------------------------------
    bool validPosi(int posi, bool checkWidth = false); 
    
    // --------------------------------
    // Validates the display has sufficient size for a multi-LED update 
    //
    // Parameters:
    // startPosi: the position we'd like to start our check from (the position of the first LED)
    // num: the number of LED's we'd like to update
    // checkWidth: determines whether we are checking against the width or height (checks height by default)
    //
    // Returns:
    // A boolean representing if the checked length was valid
    // --------------------------------
    bool validLength(int startPosi, int num, bool checkWidth = false);
};