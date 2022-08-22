#include "LEDGrid.h"
#include "LED.h"

bool validSize(int, int, int, int);
bool validEntries(int, int, LED***);

LEDGrid::LEDGrid(int rows, int cols) {
    this->grid = new LED**[rows];
    this->rows = rows;
    this->cols = cols;

    for(int i = 0; i < rows; i++) {
        this->grid[i] = new LED*[cols];
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            this->grid[i][j] = new LED();
        }
    }
}

LEDGrid::~LEDGrid() {
    for(int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->cols; j++) {
            delete this->grid[i][j];
        }
    }
}

LED ***LEDGrid::getDisplay() {
    return this->grid;
}

void LEDGrid::turnOff() {
    for(int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->cols; j++) {
            this->grid[i][j]->setRGB(LED::MIN_VALUE, LED::MIN_VALUE, LED::MIN_VALUE);
        }
    }
}

void LEDGrid::updateLEDs(int, int, LED *a) {

}

void LEDGrid::updateLEDRange(int, int, int, LED *a) {

}

void LEDGrid::copyDisplayElement(int, int) {

}

void LEDGrid::updateDisplay(int numRows, int numCols, LED ***newDisplay) {
    int red, green, blue; 

    if(validSize(numRows, this->rows, numCols, this->cols) && validEntries(this->rows, this->cols, newDisplay)) {
        for(int i = 0; i < this->rows; i++) {
            for(int j = 0; j < this->cols; j++) {
                red = newDisplay[i][j]->getRed();
                green = newDisplay[i][j]->getGreen();
                blue = newDisplay[i][j]->getBlue();
                this->grid[i][j]->setRGB(red, green, blue);
            }
        }
    }
}

bool validSize(int numRows, int currRows, int numCols, int currCols) {
    return numRows == currRows && numCols == currCols;
}

bool validEntries(int rows, int cols, LED ***newDisplay) {
    bool hasValidEntries = newDisplay;
    
    for(int i = 0; i < rows && hasValidEntries; i++) {
        for(int j = 0; j < cols && hasValidEntries; j++) {
            if(!newDisplay[i] || !newDisplay[i][j]) {
                hasValidEntries = false;
            }
        }
    }

    return hasValidEntries;
}