#include "SolidPattern.h"
#include "LEDStrip.h"
#include "LEDGrid.h"
#include "LED.h"

SolidPattern::SolidPattern(int red, int green, int blue) {
    this->fill = new LED();
    this->fill->setRGB(red, green, blue);
}

LED ***SolidPattern::usePattern(int frequency, LEDDisplay *display) {
    display->updateLEDs(0, 0, display->getHeight(), this->fill);

    for(int i = 0; i < display->getWidth(); i ++) {
        display->copyDisplayElement(0, i);
    }

    return display->getDisplay();
}