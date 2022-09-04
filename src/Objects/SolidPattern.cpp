#include "SolidPattern.h"
#include "LEDStrip.h"
#include "LEDGrid.h"
#include "LED.h"

LED ***SolidPattern::usePattern(int frequency, LEDDisplay *display) {
    LED ***newDisplay = display->getDisplay(); //this is broken

    for(int i = 0; i < display->getWidth(); i ++) {
        for(int j = 0; j < display->getHeight(); j++) {
            newDisplay[i][j]->setRGB(this->RED, this->GREEN, this->BLUE);
        }
    }

    return newDisplay;
}