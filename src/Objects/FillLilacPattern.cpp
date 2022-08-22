#include "FillLilacPattern.h"
#include "LEDStrip.h"
#include "LEDGrid.h"
#include "LED.h"

const int RED = 206;
const int GREEN = 162;
const int BLUE = 253;

FillLilacPattern::FillLilacPattern() {
    this->lilacLED = new LED();
    this->lilacLED->setRGB(RED, GREEN, BLUE);
}

LED ***FillLilacPattern::usePattern(int rows, int cols, int frequency, LEDDisplay*) {
    LED *** lilacDisplay = new LED**[rows];

    for(int i = 0; i < rows; i++) {
        lilacDisplay[i] = new LED*[cols];
    }

    for(int i = 0; i < rows; i ++) {
        for(int j = 0; j < cols; j++) {
            lilacDisplay[i][j] == this->lilacLED;
        }
    }

    return lilacDisplay;
}