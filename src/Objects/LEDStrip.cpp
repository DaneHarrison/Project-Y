#include "LEDStrip.h"
#include "LED.h"
//mention that a height must be greater than 0 otherwise problems occur
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

    if(srcLED) {
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

    for(int i = 0; i < height && newDisplay; i++) {
        if(newDisplay[i] && newDisplay[i][0]) {
            red = newDisplay[i][0]->getRed();
            green = newDisplay[i][0]->getGreen();
            blue = newDisplay[i][0]->getBlue();

            this->strip[i]->setRGB(red, green, blue);
        }
    }
}

void LEDStrip::copyDisplayElement(int src, int dest) {
    int red = this->strip[src]->getRed();
    int green = this->strip[src]->getGreen();
    int blue = this->strip[src]->getBlue();

    this->strip[dest]->setRGB(red, green, blue);
}