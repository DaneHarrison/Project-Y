#include "LEDStrip.h"
#include "LED.h"

LEDStrip::LEDStrip(int height) : LEDDisplay(height, 1){
    this->strip = new LED*[height];
    
    for(int i = 0; i < height; i++) {
        this->strip[i] = new LED();
    }
}

LEDStrip::~LEDStrip() {
    for(int i = 0; i < this->getHeight(); i++) {
        delete this->strip[i];
    }
}

void LEDStrip::turnOff() {
    for(int i = 0; i < this->getHeight(); i ++) {
        this->strip[i]->setRGB(LED::MIN_VALUE, LED::MIN_VALUE, LED::MIN_VALUE);
    }
}

LED ***LEDStrip::getDisplay() {
    LED ***copy = new LED**[this->getHeight()];
    int red, green, blue;

    for(int i = 0; i < this->getHeight(); i++) {
        copy[i] = new LED*[this->getWidth()];
    }

    for(int i = 0; i < this->getHeight(); i++) {
        red = this->strip[i]->getRed();
        green = this->strip[i]->getGreen();
        blue = this->strip[i]->getBlue();

        copy[i][0] = new LED();
        copy[i][0]->setRGB(red, green, blue);
    }

    return copy;
}

void LEDStrip::updateLEDs(int xPosi, int yPosi, int num, LED *srcLED) {
    int red, green, blue;
    
    if(srcLED && this->validLength(yPosi, num)) {
        red = srcLED->getRed();
        green = srcLED->getGreen();
        blue = srcLED->getBlue();
        
        for(int i = 0; i < num; i++) {
            this->strip[yPosi + i]->setRGB(red, green, blue);
        }
    }
}

void LEDStrip::updateDisplay(int height, int width, LED ***newDisplay) {
    int red, green, blue;

    if(newDisplay && this->validLength(0, height - 1)) {
        for(int i = 0; i < height; i++) {
            if(newDisplay[i] && newDisplay[i][0]) {
                red = newDisplay[i][0]->getRed();
                green = newDisplay[i][0]->getGreen();
                blue = newDisplay[i][0]->getBlue();

                this->strip[i]->setRGB(red, green, blue);
            }
        }
    }
}

void LEDStrip::copyDisplayElement(int src, int dest) {
    int red, green, blue;

    if(this->validPosi(src) && this->validPosi(dest)) {
        red = this->strip[src]->getRed();
        green = this->strip[src]->getGreen();
        blue = this->strip[src]->getBlue();

        this->strip[dest]->setRGB(red, green, blue);
    }
}