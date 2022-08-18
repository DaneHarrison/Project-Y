#pragma once
#include "../Interfaces/Device.h"

class Arduino : public Device {
public:
    void start();
};