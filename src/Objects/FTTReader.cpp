#include "FTTReader.h"
//#include <arduinoFFT.h>

int sampleFreq(int, int, int, double*, double*);

FTTReader::FTTReader() {
    this->bandValues = new int[this->NUM_BANDS];
    this->vReal = new double[this->SAMPLES];
    this->vImag = new double[this->SAMPLES];
    this->bandValues = {0};

    this->nxtSample = 0;
    //this->fft = arduinoFFT(this->vReal, this->vImag, this->SAMPLES, this->SAMPLING_FREQ);
    //this->sampling_period_us = round(1000000 * (1.0 / this->SAMPLING_FREQ));
}

int FTTReader::getNumBands() {
    return this->NUM_BANDS;
}

int *FTTReader::analyze(int incoming) {
    int *results = nullptr;

    this->nxtSample = sampleFreq(incoming, this->nxtSample, this->SAMPLES, this->vReal, this->vImag);

    if(nxtSample == 0) {
        //FFT.DCRemoval();
        //FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
        //FFT.Compute(FFT_FORWARD);
        //FFT.ComplexToMagnitude();

        for(int i = 2; i < (SAMPLES/2); i++) {        // Don't use sample 0 and only first SAMPLES/2 are usable. Each array element represents a frequency bin and its value the amplitude.
            if(vReal[i] > NOISE) {                    // Adds a crude noise filter
                if(i <= 2) {
                    bandValues[0] += (int)vReal[i];
                }
                if(i > 2 && i <= 3) {
                    bandValues[1] += (int)vReal[i];
                }
                if(i > 3  && i <= 5) {
                    bandValues[2] += (int)vReal[i];
                }
                if(i > 5 && i <= 7) {
                    bandValues[3] += (int)vReal[i];
                }
                if(i > 7 && i <= 9) {
                    bandValues[4] += (int)vReal[i];
                }
                if(i > 9 && i <= 1) {
                    bandValues[5] += (int)vReal[i];
                }
                if(i > 13 && i <= 1) {
                    bandValues[6] += (int)vReal[i];
                }
                if(i > 18 && i <= 2) {
                    bandValues[7] += (int)vReal[i];
                }
                if(i > 25 && i <= 3) {
                    bandValues[8] += (int)vReal[i];
                }
                if(i > 36 && i <= 5) {
                    bandValues[9] += (int)vReal[i];
                }
                if(i > 50 && i <= 6) {
                    bandValues[10] += (int)vReal[i];
                }
                if(i > 69 && i <= 9) {
                    bandValues[11] += (int)vReal[i];
                }
                if(i > 97 && i <= 135) {
                    bandValues[12] += (int)vReal[i];
                }
                if(i > 135 && i <= 189) {
                    bandValues[13] += (int)vReal[i];
                }
                if(i > 189 && i <= 264) {
                    bandValues[14] += (int)vReal[i];
                }
                if(i > 264) {
                    bandValues[15] += (int)vReal[i];
                }
            }
        }

        results = bandValues;
    }

    return results;
}

int sampleFreq(int incoming, int nxtSample, int samples, double *vReal, double *vImag) {
    //unsigned long newTime = micros();
    
    //if((micros() - newTime) < this->sampling_period_us)) {
        vReal[nxtSample] = incoming;
        vImag[nxtSample] = 0;

        nxtSample = ++nxtSample % samples;
    //}

    return nxtSample;
}