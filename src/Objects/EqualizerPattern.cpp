#include "EqualizerPattern.h"
#include "LEDDisplay.h"
#include "FTTReader.h"
#include "LED.h"

EqualizerPattern::EqualizerPattern() {
    this->analyzer = new FTTReader();
    this->fill = new LED();
    this->fill->setRGB(206, 162, 253);
}

LED ***EqualizerPattern::usePattern(int frequency, LEDDisplay* display) {
    int *bands = this->analyzer->analyze(frequency);
    int barHeight;

    if(bands) {
        for (int i = 0; i < this->analyzer->getNumBands(); i++) {

        barHeight = bands[i]/this->AMPLITUDE;
        if (barHeight >= display->getHeight()) {
            barHeight = display->getHeight();
        }

        display->updateLEDs(i, 0, barHeight, this->fill);
    }
}