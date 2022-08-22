//
//
//
#pragma once
#include "../Interfaces/Device.h"

class Arduino : public Device {
private:
    static const int MIC_PIN;
    static const int DISPLAY_PIN;
    static const int DISPLAY_WIDTH;
    static const int DISPLAY_HEIGHT;

public:
    Arduino();
    int listen();
    int getDisplayWidth();
    int getDisplayHeight();
    void updateLEDDisplay(LED***);
};