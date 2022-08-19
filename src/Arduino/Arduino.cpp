#include "Arduino.h"
#include "../Objects/MicInput.h"
#include "../Logic/VisualizerLogic.h"
#include <iostream>
using namespace std;

void Arduino::start() {
    cout << "hi";
    //VisualizerLogic visualizer = new VisualizerLogic();
    
    while(true) {
        //this->input->listen();
        //visualizer ->(pass audio into logic)
        //this->display->updateDisplay(visualizer.process())
    }
}

void Device::setAudioInput(AudioInput* currInput) {
    this->input = currInput;
}

void Device::setLEDDisplay(LEDDisplay* currDisplay) {
    this->display = currDisplay;
}