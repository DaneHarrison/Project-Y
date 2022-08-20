#include "LED.h"

bool validColor(int);
int normalizeColor(int);

LED::LED() {
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

int LED::getRed() {
    return this->red;
}

int LED::getGreen() {
    return this->green;
}

int LED::getBlue() {
    return this->blue;
}

void LED::setRed(int newRed) {
    if(validColor(newRed)) {
        this->red = newRed;
    }
    else {
        this->red = normalizeColor(newRed);
    }
}

void LED::setGreen(int newGreen) {
    if(validColor(newGreen)) {
        this->green = newGreen;
    }
    else {
        this->green = normalizeColor(newGreen);
    }
}

void LED::setBlue(int newBlue) {
    if(validColor(newBlue)) {
        this->blue = newBlue;
    }
    else
    {
        this->blue = normalizeColor(newBlue);
    }
}

void LED::setRGB(int newRed, int newGreen, int newBlue) {
    this->setRed(newRed);
    this->setGreen(newGreen);
    this->setBlue(newBlue);
}

bool validColor(int newVal) {
    return newVal >= LED::MIN_VALUE && newVal <= LED::MAX_VALUE;
}

int normalizeColor(int extremeVal) {
    int normalizedVal = LED::MIN_VALUE;

    if(extremeVal > LED::MAX_VALUE) {
        normalizedVal = LED::MAX_VALUE;
    }

    return normalizedVal;
}