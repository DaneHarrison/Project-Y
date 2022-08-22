// --------------------------------
// Class: VisualizerLogic
// Author: Dane
//
// Holds logic for the audio visualizer - responsible for pattern management and display generation
// --------------------------------
#pragma once
class PatternStrategy;
class LEDDisplay;
class LED;

class VisualizerLogic {
private:
    PatternStrategy *selected;  //The pattern that is currently responsible for display generation
    LEDDisplay *currDisplay;    //The current display
    int height;                 //The height of the display
    int width;                  //The width of the display

public:
    VisualizerLogic();


    // --------------------------------
    // Sets the size for the current display and acts as an abstract Factory for the LEDDisplay
    //
    // Parameters:
    // height: The height of the display
    // width: The width of the display
    // --------------------------------
    void setSize(int height, int width);


    // --------------------------------
    // Generates a display based on frequency and the currently selected pattern
    //
    // Parameters:
    // frequency: represents the calculated audio frequency
    //
    // Returns:
    // A 2D array of LEDs that make up the generated display
    // --------------------------------
    LED ***process(int frequency);
};