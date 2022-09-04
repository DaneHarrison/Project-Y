#include "LEDDisplay.h"
#include "LED.h"

LEDDisplay::LEDDisplay(int height, int width) {
    this->height = height;
    this->width = width;
}

int LEDDisplay::getHeight() {
    return this->height;
}

int LEDDisplay::getWidth() {
    return this->width;
}

// bool validEntries(int height, int width, LED ***newDisplay) {
//     bool hasValidEntries = newDisplay;
    
//     for(int i = 0; i < width && hasValidEntries; i++) {
//         for(int j = 0; j < height && hasValidEntries; j++) {
//             if(!newDisplay[i] || !newDisplay[i][j]) {   //check if a pointer is actually nullptr
//                 hasValidEntries = false;
//             }
//         }
//     }

//     return hasValidEntries;
// }