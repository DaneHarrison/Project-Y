#include "Objects/MicInput.h"
#include "Objects/LEDGrid.h"
#include "Arduino/Arduino.h"
#include <iostream>
using namespace std;

void main() {
    AudioInput *input = new AudioInput();
    LEDGrid *display = new LEDGrid();
    Arduino *device = new Arduino();

    device->setAudioInput(input);
    device->setLEDDisplay(display);
    device->start();
}