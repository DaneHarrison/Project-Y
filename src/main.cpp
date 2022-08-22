// --------------------------------
// Powers a wearable LED display shirt that lights up according to audio frequency
// --------------------------------
#include "Logic/VisualizerLogic.h"
#include "Interfaces/LEDDisplay.h"
#include "Arduino/Arduino.h"


void main() {
    VisualizerLogic *visualizer = new VisualizerLogic();    //Holds the audio visualizer logic
    Device *device = new Arduino();                         //The device that powers the visualizer
    LED ***display;                                         //The current display
    int audio;                                              //The input audio frquency

    visualizer->setSize(device->getDisplayWidth(), device->getDisplayHeight());

    while(true) {
        audio = device->listen();   
        display = visualizer->process(audio);
        device->updateLEDDisplay(display);
    }
}