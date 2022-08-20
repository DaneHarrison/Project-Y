#include "Arduino.h"
#include "../Objects/LEDGrid.h"
#include "../Objects/LEDStrip.h"

const int Arduino::MIC_PIN = 5;
const int Arduino::DISPLAY_PIN = 5;
const int Arduino::DISPLAY_WIDTH = 5;
const int Arduino::DISPLAY_HEIGHT = 5;

int Arduino::listen() {
    return 100;
}

int Arduino::getDisplayWidth() {
    return Arduino::DISPLAY_WIDTH;
}

int Arduino::getDisplayHeight() {
    return Arduino::DISPLAY_HEIGHT;
}

void Arduino::updateLEDDisplay(LEDDisplay*) {}