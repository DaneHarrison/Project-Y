#include "Logic/VisualizerLogic.h"
#include "Interfaces/LEDDisplay.h"
#include "Arduino/Arduino.h"


void main() {
    VisualizerLogic *visualizer = new VisualizerLogic();
    Device *device = new Arduino();
    LED ***display;
    int audio;

    visualizer->setSize(device->getDisplayWidth(), device->getDisplayHeight());

    while(true) {
        audio = device->listen();   
        display = visualizer->process(audio);
        device->updateLEDDisplay(display);
    }
}