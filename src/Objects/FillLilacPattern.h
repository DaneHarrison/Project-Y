#pragma once

#include "../Interfaces/PatternStrategy.h"

class FillLilacPattern : public PatternStrategy {
private:
    LED *lilacLED;
public:
    FillLilacPattern();
    LED ***usePattern(int, int, int, LEDDisplay*);
};