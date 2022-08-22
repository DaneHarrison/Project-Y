#pragma once
class PatternStrategy;
class LEDDisplay;
class LED;

class VisualizerLogic {
private:
    PatternStrategy *selected; //eventually change to a manager
    LEDDisplay *currDisplay;
    int rows;
    int cols;

public:
    VisualizerLogic();
    void setSize(int, int);
    LED ***process(int);
};