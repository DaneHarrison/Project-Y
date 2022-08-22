// --------------------------------
// Class: Arduino
// Author: Dane
//
// Represents an arduino implementation of a device that displays patterns 
// based on audio frequency
// --------------------------------
#pragma once
#include "../Interfaces/Device.h"

class Arduino : public Device {
private:
    static const int MIC_PIN;           //Arduino pin that controls audio input
    static const int DISPLAY_PIN;       //Arduino pin that controls the LEDDisplay output
    static const int DISPLAY_WIDTH;     //The LED Display's width
    static const int DISPLAY_HEIGHT;    //The LED DIsplay's height

public:
    Arduino();
    
    
    // --------------------------------
    // Detects audio frequency through an analog pin
    //
    // Returns: 
    // An integer representing the audio frequency 
    // --------------------------------
    int listen();


    // --------------------------------
    // Fetches the width of the display (getter)
    //
    // Returns:
    // An integer representing the width of the display
    // --------------------------------
    int getDisplayWidth();
    

    // --------------------------------
    // Fetches the height of the display (getter)
    //
    // Returns:
    // An integer representing the height of the display
    // --------------------------------
    int getDisplayHeight();


    // --------------------------------
    // Updates the current display to match the inputs (setter)
    //
    // Parameters:
    // newDisplay: the input display we'd like to use to update our current display
    // --------------------------------
    void updateLEDDisplay(LED ***newDisplay);
};