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

void LEDGrid::turnOff() {
    for(int i = 0; i < this->getWidth(); i++) {
        this->grid[i]->turnOff();
    }
}

void LEDGrid::updateLEDs(int xPosi, int yPosi, int num, LED *src) {
    LEDStrip *curr;

    if(this->validPosi(xPosi, true)) {
        curr = this->grid[xPosi];
        curr->updateLEDs(xPosi, yPosi, num, src);
    }
}

void LEDGrid::copyDisplayElement(int src, int dest) {
    int height, width;
    LED ***curr;

    if(this->validPosi(src, true) && this->validPosi(dest, true)) {
        curr = this->grid[src]->getDisplay();
        height = this->grid[src]->getHeight();
        width = this->grid[src]->getWidth();

        this->grid[dest]->updateDisplay(height, width, curr);
    }
}

LED ***LEDGrid::getDisplay() {
    LED ***copy = new LED**[this->getHeight()];
    LED ***curr;

    for(int i = 0; i < this->getHeight(); i++) {
        copy[i] = new LED*[this->getWidth()]; 
    }

    for(int i = 0; i < this->getWidth(); i++) {
        curr = this->grid[i]->getDisplay();
        
        for(int j = 0; j < this->getHeight(); j++) {    
            copy[j][i] = curr[j][0];
        }        
    }

    return copy;
}

void LEDGrid::updateDisplay(int width, int height, LED ***newDisplay) {
    int red, green, blue;
    LEDStrip *currStrip;
    LED *currLED = new LED();
    
    if(newDisplay && this->validLength(0, height - 1) && this->validLength(0, width - 1, true)) {
        for(int i = 0; i < width; i++) {
            currStrip = this->grid[i];

            for(int j = 0; j < height; j++) {
                if(newDisplay[i] && newDisplay[j][i]) {
                    red = newDisplay[j][i]->getRed();
                    green = newDisplay[j][i]->getGreen();
                    blue = newDisplay[j][i]->getBlue();
                    
                    currLED->setRGB(red, green, blue);
                    currStrip->updateLEDs(0, j, 1, currLED);
                }
            }
        }
    }
}

LEDStrip *LEDGrid::getStrip(int posi) {
    LEDStrip *strip = nullptr;

    if(this->validPosi(posi, true)) {
        strip = this->grid[posi];
    }

    return strip;
}