#pragma once
class LEDDisplay;
class LED;

class PatternStrategy {
public:
    virtual LED ***usePattern(int, int, int, LEDDisplay*) = 0;
};