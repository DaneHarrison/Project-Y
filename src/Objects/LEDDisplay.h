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
    int height;
    int width;

public:
    LEDDisplay(int height, int width);


    // --------------------------------
    // Fetches the display's height (getter)
    //
    // Returns:
    // An integer that refers to the displays height
    // --------------------------------
    virtual int getHeight();


    // --------------------------------
    // Fetches the current width (getter)
    //
    // Returns:
    // An integer that refers to the displays width
    // --------------------------------
    virtual int getWidth();


    // --------------------------------
    // Turns off the entire display
    // --------------------------------
    virtual void turnOff() = 0;


    // --------------------------------
    // Fetches the current display (getter)
    //
    // Returns:
    // A copy of the 2D array of LEDs that make up the current display
    // --------------------------------
    virtual LED ***getDisplay() = 0;
    

    // --------------------------------
    // Updates a range of LEDs
    //
    // Parameters:
    // height: the height of the LEDs we'd like to start updating at
    // width: the width of the LEDs we'd like to update
    // num: the number of LEDs we'd like to update
    // srcLED: the new LED we'd like to insert into our display
    // --------------------------------
    virtual void updateLEDs(int height, int width, int num, LED *srcLED) = 0;


    // --------------------------------
    // Copies LED contents to others
    //
    // Parameters:
    // src: the LED location in the display we'd like to copy
    // dest: the LED location in the display we'd like to modify
    // --------------------------------
    virtual void copyDisplayElement(int src, int dest) = 0;
    
    
    // --------------------------------
    // Overwrites the current display (if sizes and contents are compatible - no nullptrs and same size)
    //
    // newDisplay: the input display we'd like to use to update our current display
    // --------------------------------
    virtual void updateDisplay(int height, int width, LED ***newDisplay) = 0;

// protected:
//     bool validateSize(int, int, LED***);
//     bool validateEntries(int, int, LED***);
};