#include "VisualizerLogic.h"
#include "../Objects/LEDGrid.h"
#include "../Objects/LEDStrip.h"
#include "../Objects/FillLilacPattern.h"

VisualizerLogic::VisualizerLogic() {
    this->selected = new FillLilacPattern();
}

void VisualizerLogic::setSize(int height, int width) {
    if(width == 0) {
        this->currDisplay = new LEDStrip(height);
    }
    else {
        this->currDisplay = new LEDGrid(height, width);
    }

    this->height = height;
    this->width = width;
}

LED ***VisualizerLogic::process(int frequency) {
    return this->selected->usePattern(this->height, this->width, frequency, this->currDisplay);
}