//template pattern, dependency inversion
#pragma once
class LEDDisplay;
class AudioInput;

class Device {
private:
    LEDDisplay *display;
    AudioInput *input;
    
public:
    virtual void start() = 0;
    virtual void setLEDDisplay(LEDDisplay*); //needs a display -> has the LED strips (array of strips -> array of leds)
    virtual void setAudioInput(AudioInput*); //needs a mic
};  