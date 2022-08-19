#include "Arduino/Arduino.h"
#include "Objects/LEDGrid.h"


void main() {
    Arduino *device = new Arduino();
    LEDGrid *display = new LEDGrid();
    

    device->setLEDDisplay(display);
    device->start();
}