#pragma once
class PatternStrategy;
class LEDDisplay;

class VisualizerLogic {
private:
    PatternStrategy *selected; //eventually change to a manager
    LEDDisplay *currDisplay;
    int rows;
    int cols;

public:
    void init(int, int);
    LEDDisplay *process(int);
};