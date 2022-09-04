#include "LEDDisplay.h"
#include "LED.h"

LEDDisplay::LEDDisplay(int height, int width) {
    this->height = height;
    this->width = width;
}

int LEDDisplay::getHeight() {
    return this->height;
}

int LEDDisplay::getWidth() {
    return this->width;
}

bool LEDDisplay::validPosi(int posi, bool checkWidth) {
    bool isValid;

    if(checkWidth) {
        isValid = posi >= 0 && posi < this->width;
    }
    else {
        isValid = posi >= 0 && posi < this->height;
    }

    return isValid;
}

bool LEDDisplay::validLength(int startPosi, int num, bool checkWidth) {
    bool isValid;

    if(checkWidth) {
        isValid = this->validPosi(startPosi, true) && startPosi + num <= this->width;
    }
    else {
        isValid = this->validPosi(startPosi) && startPosi + num <= this->height;
    }

    return isValid;
}