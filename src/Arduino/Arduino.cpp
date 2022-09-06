//#include <FastLED.h>
#include "Arduino.h"
#include "../Objects/LEDGrid.h"
#include "../Objects/LEDStrip.h"
#include "../Objects/LED.h"

const int Arduino::MIC_PIN = 5;
const int Arduino::DISPLAY_PIN = 5;
const int Arduino::DISPLAY_WIDTH = 5;
const int Arduino::DISPLAY_HEIGHT = 5;
//CRGB display[DISPLAY_HEIGHT*DISPLAY_WIDTH];

Arduino::Arduino() {
    //FastLED.addLeds<NEOPIXEL, DISPLAY_PIN>(display, DISPLAY_HEIGHT*DISPLAY_WIDTH);
}

int Arduino::listen() {
    //return analogRead(MIC_PIN);
    return 0; 
}

int Arduino::getDisplayWidth() {
    return Arduino::DISPLAY_WIDTH;
}

int Arduino::getDisplayHeight() {
    return Arduino::DISPLAY_HEIGHT;
}

void Arduino::updateLEDDisplay(LED ***newDisplay) {
    int red, green, blue;
    int currLED = 0;

    for(int i = 0; i < Arduino::DISPLAY_WIDTH; i++) {
        for(int j = 0; j < Arduino::DISPLAY_HEIGHT; j++) {
            red = newDisplay[i][j]->getRed();
            green = newDisplay[i][j]->getGreen();
            blue = newDisplay[i][j]->getBlue();
            
            //display[currLED] = CRGB(red, green, blue);
            currLED++;
        }
    }

    //FastLED.clear();
    //FastLED.show();
}