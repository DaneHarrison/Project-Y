#pragma once
class LEDDisplay;

class PatternStrategy { //can add randomization into this - can be selected 
public:
    virtual LEDDisplay *usePattern(int, int, int) = 0;
};