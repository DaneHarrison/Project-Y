// --------------------------------
// Class: LED
// Author: Dane
//
// Manages an LED; access and modify its RBG values inside the range [0, 255]
// --------------------------------
#pragma once
#include "../Interfaces/LEDDisplay.h"

class LED {
private:
    int red;    //The red value in an LED
    int green;  //The green value in an LED
    int blue;   //The blue value in an LED

public:
    static const int MIN_VALUE = 0;     //Lowest valid RGB value (black)
    static const int MAX_VALUE = 255;   //Largest valid RGB value (white)

    LED();


    // --------------------------------
    // Fetches the red value in an LED (getter)
    //
    // Returns:
    // An integer representing the red value in an LED
    // --------------------------------
    int getRed();


    // --------------------------------
    // Fetches the green value in an LED (getter)
    //
    // Returns:
    // An integer representing the green value in an LED
    // --------------------------------
    int getGreen();


    // --------------------------------
    // Fetches the blue value in an LED (getter)
    //
    // Returns:
    // An integer representing the blue value in an LED
    // --------------------------------
    int getBlue();

    // --------------------------------
    // Sets the red value in an LED
    //
    // Parameters:
    // newRed: the new red value we'd like to assign to the LED
    // --------------------------------
    void setRed(int newRed);

    // --------------------------------
    // Sets the green value in an LED
    //
    // Parameters:
    // newGreen: the new green value we'd like to assign to the LED
    // --------------------------------
    void setGreen(int newGreen);

    // --------------------------------
    // Sets the blue value in an LED
    //
    // Parameters:
    // newBlue: the new blue value we'd like to assign to the LED
    // --------------------------------
    void setBlue(int newBlue);

    // --------------------------------
    // Sets the red, green and blue values in an LED
    //
    // Parameters:
    // newRed: the new red value we'd like to assign to the LED
    // newGreen: the new green value we'd like to assign to the LED
    // newBlue: the new blue value we'd like to assign to the LED
    // --------------------------------
    void setRGB(int newRed, int newGreen, int newBlue);
};