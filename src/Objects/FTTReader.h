// --------------------------------
// Class: FTTReader
// Author: s-marley - https://github.com/s-marley/ESP32_FFT_VU
//
// Uses Fast Fourier Transformations to interpret audio frequency given audio input
// --------------------------------
#pragma once
class arduinoFFT;

class FTTReader {
private:
    const int SAMPLES = 1024;       //must be a power of 2
    const int SAMPLING_FRQ = 40000; //hz, must be 40000 or less due to ADC conversion time. Determines maximum frequency that can be analysed by the FFT Fmax=sampleF/2.
    const int NUM_BANDS = 16;       //to change this, you will need to change the bunch of if statements describing the mapping from bins to bands
    const int NOISE = 500;          //used as a crude noise filter, values below this are ignored

    int *bandValues;    //holds the values for each frequency
    double *vReal;      //holds real audio frequency values
    double *vImag;      //holds imaginairy audio frequency values

    int nxtSample;      //the next sample to fill
    arduinoFFT *fft;    //performs audio analysis
    unsigned int sampling_period_us;    //controls which inputs are added to the samples

public:
    FTTReader();

    int getNumBands();

    int *analyze(int incoming);
};