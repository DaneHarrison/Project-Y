// --------------------------------
// Class: Device
// Author: Dane
//
// Represents an abstract device that displays patterns based on audio frequency
// --------------------------------
#pragma once
class LEDDisplay;
class LED;

class Device {
public:
    // --------------------------------
    // Detects audio frequency
    //
    // Returns: 
    // An integer representing the audio frequency 
    // --------------------------------
    virtual int listen() = 0;


    // --------------------------------
    // Fetches the width of the display (getter)
    //
    // Returns:
    // An integer representing the width of the display
    // --------------------------------
    virtual int getDisplayWidth() = 0;


    // --------------------------------
    // Fetches the height of the display (getter)
    //
    // Returns:
    // An integer representing the height of the display
    // --------------------------------
    virtual int getDisplayHeight() = 0;


    // --------------------------------
    // Updates the current display to match the inputs (setter)
    //
    // Parameters:
    // newDisplay: the input display we'd like to use to update our current display
    // --------------------------------
    virtual void updateLEDDisplay(LED ***newDisplay) = 0;
};  