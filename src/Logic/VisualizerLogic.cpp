#include "VisualizerLogic.h"
#include "../Objects/LEDGrid.h"
#include "../Objects/LEDStrip.h"
#include "../Objects/FillLilacPattern.h"

VisualizerLogic::VisualizerLogic() {
    this->selected = new FillLilacPattern();
}

void VisualizerLogic::setSize(int rows, int cols) {
    if(cols == 0) { //Abstract Factory for LEDDisplays
        this->currDisplay = new LEDStrip(rows);
    }
    else {
        this->currDisplay = new LEDGrid(rows, cols);
    }

    this->rows = rows;
    this->cols = cols;
}

LED ***VisualizerLogic::process(int frequency) { //can add randomization into this - can be selected 
    return this->selected->usePattern(this->rows, this->cols, frequency, this->currDisplay);
}