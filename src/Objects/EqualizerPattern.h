// --------------------------------
// Class: EqualizerPattern
// Author: Dane
// 
// Creates an equalizer pattern based on audio frequency
// --------------------------------
#pragma once
class FTTReader;
class LED;
#include "../Interfaces/PatternStrategy.h"


class EqualizerPattern : public PatternStrategy {
private:
    const int AMPLITUDE = 1000; // The total height (can be used to control sensitivity)
    FTTReader *analyzer;        // Performs the FFT
    LED *fill;                  // Used to light up the display

public:
    EqualizerPattern();

    LED ***usePattern(int frequency, LEDDisplay* display);
};