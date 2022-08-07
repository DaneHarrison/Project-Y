#include <Arduino.h>
#include <VisualizerLogic.h>
#include <AudioReader.h>
#include <LEDGrid.h>

void main() {
    Arduino* device = new Arduino();
    FTTReader* audioReader = new FTTReader();
    VisualizerLogic* visualizer = new VisualizerLogic();
    LEDGrid* display = new LEDGrid(arduino.LED_WIDTH, arduino.LED_HEIGHT);
    
    visualizer.init(device, display, audioReader);
    visualizer.start();
}