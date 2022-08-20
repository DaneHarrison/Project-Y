//
//
//
#pragma once
class LEDDisplay;

#include "../Interfaces/Device.h"

class Arduino : public Device {
private:
    static const int MIC_PIN;
    static const int DISPLAY_PIN;
    static const int DISPLAY_WIDTH;
    static const int DISPLAY_HEIGHT;

public:
    int listen();
    int getDisplayWidth();
    int getDisplayHeight();
    void updateLEDDisplay(LEDDisplay*);
};