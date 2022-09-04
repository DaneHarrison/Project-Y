#include "LEDStrip.h"
#include "LEDGrid.h"
#include "LED.h"


LEDGrid::LEDGrid(int height, int width) : LEDDisplay(height, width) {
    this->grid= new LEDStrip*[width];

    for(int i = 0; i < width; i++) {
        this->grid[i] = new LEDStrip(height);
    }
}

LEDGrid::~LEDGrid() {
    for(int i = 0; i < this->getWidth(); i++) {
        delete this->grid[i];
    }
}

void LEDGrid::turnOff() {}

void LEDGrid::updateLEDs(int xPosi, int yPosi, int num, LED *src) {}

void LEDGrid::copyDisplayElement(int srcPosi, int destPosi) {}

LED ***LEDGrid::getDisplay() {
    return nullptr;
}

void LEDGrid::updateDisplay(int height, int width, LED ***newDisplay) {}