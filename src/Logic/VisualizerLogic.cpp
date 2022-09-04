#include "VisualizerLogic.h"
#include "../Objects/LEDGrid.h"
#include "../Objects/LEDStrip.h"
#include "../Objects/SolidPattern.h"

VisualizerLogic::VisualizerLogic() {
    this->selected = new SolidPattern();
}

void VisualizerLogic::setSize(int height, int width) {
    if(width == 1) {
        this->currDisplay = new LEDStrip(height);
    }
    else {
        this->currDisplay = new LEDGrid(height, width);
    }
}

LED ***VisualizerLogic::process(int frequency) {
    LED ***newDisplay = this->selected->usePattern(frequency, this->currDisplay);
    currDisplay->updateDisplay(1, 1, newDisplay); //will need to update

    return this->currDisplay->getDisplay();
}