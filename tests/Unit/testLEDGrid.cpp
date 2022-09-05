#include "../../src/Objects/LEDGrid.h"
#include "../../src/Objects/LEDStrip.h"
#include "../../src/Objects/LED.h"
#include "../catch.hpp"

TEST_CASE("Basic LEDGrid test cases") {
    LED *testLED = new LED();
    LEDGrid *testGrid;
    LED ***altTestDisplay;
    LED ***testDisplay;

    SECTION("Testing default values") {
        testGrid = new LEDGrid(5, 5);
        testDisplay = testGrid->getDisplay();
        
        REQUIRE(testGrid->getHeight() == 5);
        REQUIRE(testGrid->getWidth() == 5);

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        testGrid = new LEDGrid(7, 3);
        testDisplay = testGrid->getDisplay();
        
        REQUIRE(testGrid->getHeight() == 7);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 7; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        testGrid = new LEDGrid(2, 20);
        testDisplay = testGrid->getDisplay();
        
        REQUIRE(testGrid->getHeight() == 2);
        REQUIRE(testGrid->getWidth() == 20);

        for(int i = 0; i < 20; i++) {
            for(int j = 0; j < 2; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }
    }

    SECTION("Testing changing a single LED") {
        testLED->setRGB(5, 3, 4);
        testGrid = new LEDGrid(3, 3);
        testGrid->updateLEDs(1, 1, 1, testLED);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);
        REQUIRE(testDisplay[1][0]->getRed() == 0);
        REQUIRE(testDisplay[1][0]->getGreen() == 0);
        REQUIRE(testDisplay[1][0]->getBlue() == 0);
        REQUIRE(testDisplay[2][0]->getRed() == 0);
        REQUIRE(testDisplay[2][0]->getGreen() == 0);
        REQUIRE(testDisplay[2][0]->getBlue() == 0);
        REQUIRE(testDisplay[0][1]->getRed() == 0);
        REQUIRE(testDisplay[0][1]->getGreen() == 0);
        REQUIRE(testDisplay[0][1]->getBlue() == 0);
        REQUIRE(testDisplay[1][1]->getRed() == 5);
        REQUIRE(testDisplay[1][1]->getGreen() == 3);
        REQUIRE(testDisplay[1][1]->getBlue() == 4);
        REQUIRE(testDisplay[2][1]->getRed() == 0);
        REQUIRE(testDisplay[2][1]->getGreen() == 0);
        REQUIRE(testDisplay[2][1]->getBlue() == 0);
        REQUIRE(testDisplay[0][2]->getRed() == 0);
        REQUIRE(testDisplay[0][2]->getGreen() == 0);
        REQUIRE(testDisplay[0][2]->getBlue() == 0);
        REQUIRE(testDisplay[1][2]->getRed() == 0);
        REQUIRE(testDisplay[1][2]->getGreen() == 0);
        REQUIRE(testDisplay[1][2]->getBlue() == 0);
        REQUIRE(testDisplay[2][2]->getRed() == 0);
        REQUIRE(testDisplay[2][2]->getGreen() == 0);
        REQUIRE(testDisplay[2][2]->getBlue() == 0);


        testGrid->turnOff();
        testDisplay = testGrid->getDisplay();
        
        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i ++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        altTestDisplay = new LED**[3];
        altTestDisplay[0] = new LED*[3];
        altTestDisplay[1] = new LED*[3];
        altTestDisplay[2] = new LED*[3];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                altTestDisplay[j][i] = new LED();
            }
        }
        altTestDisplay[0][0] = testLED;
        testGrid->updateDisplay(3, 3, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        REQUIRE(testDisplay[0][0]->getRed() == 5);
        REQUIRE(testDisplay[0][0]->getGreen() == 3);
        REQUIRE(testDisplay[0][0]->getBlue() == 4);
        REQUIRE(testDisplay[1][0]->getRed() == 0);
        REQUIRE(testDisplay[1][0]->getGreen() == 0);
        REQUIRE(testDisplay[1][0]->getBlue() == 0);
        REQUIRE(testDisplay[2][0]->getRed() == 0);
        REQUIRE(testDisplay[2][0]->getGreen() == 0);
        REQUIRE(testDisplay[2][0]->getBlue() == 0);
        for(int i = 1; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }
    

        testGrid->copyDisplayElement(1, 0);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i ++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }
    }
}

TEST_CASE("More complex LEDGrid test cases") {
    LED *testLED = new LED();
    LEDStrip *testStrip;
    LEDGrid *testGrid;
    LED ***altTestDisplay;
    LED ***testDisplay;

    SECTION("Tests modifying multiple LEDs") {
        testLED->setRGB(100, 110, 120);
        testGrid = new LEDGrid(2, 2);
        testGrid->updateLEDs(1, 0, 2, testLED);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 2);
        REQUIRE(testGrid->getWidth() == 2);

        for(int i = 0; i < 2; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
            REQUIRE(testDisplay[i][1]->getRed() == 100);
            REQUIRE(testDisplay[i][1]->getGreen() == 110);
            REQUIRE(testDisplay[i][1]->getBlue() == 120);
        }


        testGrid->turnOff();
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 2);
        REQUIRE(testGrid->getWidth() == 2);

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        altTestDisplay = new LED**[2];
        altTestDisplay[0] = new LED*[2];
        altTestDisplay[1] = new LED*[2];
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j ++) {
                altTestDisplay[j][i] = new LED();
            }
        }
        altTestDisplay[0][0] = testLED;
        altTestDisplay[1][1] = testLED;
        testGrid->updateDisplay(2, 2, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 2);
        REQUIRE(testGrid->getWidth() == 2);

        REQUIRE(testDisplay[0][0]->getRed() == 100);
        REQUIRE(testDisplay[0][0]->getGreen() == 110);
        REQUIRE(testDisplay[0][0]->getBlue() == 120);
        REQUIRE(testDisplay[1][0]->getRed() == 0);
        REQUIRE(testDisplay[1][0]->getGreen() == 0);
        REQUIRE(testDisplay[1][0]->getBlue() == 0);
        REQUIRE(testDisplay[0][1]->getRed() == 0);
        REQUIRE(testDisplay[0][1]->getGreen() == 0);
        REQUIRE(testDisplay[0][1]->getBlue() == 0);
        REQUIRE(testDisplay[1][1]->getRed() == 100);
        REQUIRE(testDisplay[1][1]->getGreen() == 110);
        REQUIRE(testDisplay[1][1]->getBlue() == 120);
        
        
        testGrid->copyDisplayElement(0, 1);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 2);
        REQUIRE(testGrid->getWidth() == 2);

        for(int i = 0; i < 2; i++) {
            REQUIRE(testDisplay[0][i]->getRed() == 100);
            REQUIRE(testDisplay[0][i]->getGreen() == 110);
            REQUIRE(testDisplay[0][i]->getBlue() == 120);
            REQUIRE(testDisplay[1][i]->getRed() == 0);
            REQUIRE(testDisplay[1][i]->getGreen() == 0);
            REQUIRE(testDisplay[1][i]->getBlue() == 0);
        }
    }

    SECTION("Tests modifying all LEDs when there is an even amount") {
        testLED->setRGB(100, 110, 120);
        testGrid = new LEDGrid(2, 2);
        testGrid->updateLEDs(1, 0, 2, testLED);
        testGrid->updateLEDs(0, 0, 2, testLED);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 2);
        REQUIRE(testGrid->getWidth() == 2);

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 100);
                REQUIRE(testDisplay[j][i]->getGreen() == 110);
                REQUIRE(testDisplay[j][i]->getBlue() == 120);
            }
        }


        testGrid->turnOff();
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 2);
        REQUIRE(testGrid->getWidth() == 2);

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        altTestDisplay = new LED**[2];
        altTestDisplay[0] = new LED*[2];
        altTestDisplay[1] = new LED*[2];
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j ++) {
                altTestDisplay[j][i] = testLED;
            }
        }
        testGrid->updateDisplay(2, 2, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 2);
        REQUIRE(testGrid->getWidth() == 2);

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 100);
                REQUIRE(testDisplay[j][i]->getGreen() == 110);
                REQUIRE(testDisplay[j][i]->getBlue() == 120);
            }
        }


        testLED->setRGB(0, 0, 0);
        testGrid->updateLEDs(0, 0, 2, testLED);
        testGrid->copyDisplayElement(0, 1);
                testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 2);
        REQUIRE(testGrid->getWidth() == 2);

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }
    }

    SECTION("Tests modifying all LEDs when there is an odd amount") { 
        testLED->setRGB(100, 110, 120);
        testGrid = new LEDGrid(3, 3);
        testGrid->updateLEDs(2, 0, 3, testLED);
        testGrid->updateLEDs(1, 0, 3, testLED);
        testGrid->updateLEDs(0, 0, 3, testLED);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 100);
                REQUIRE(testDisplay[j][i]->getGreen() == 110);
                REQUIRE(testDisplay[j][i]->getBlue() == 120);
            }
        }


        testGrid->turnOff();
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        altTestDisplay = new LED**[3];
        altTestDisplay[0] = new LED*[3];
        altTestDisplay[1] = new LED*[3];
        altTestDisplay[2] = new LED*[3];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j ++) {
                altTestDisplay[j][i] = testLED;
            }
        }
        testGrid->updateDisplay(3, 3, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 100);
                REQUIRE(testDisplay[j][i]->getGreen() == 110);
                REQUIRE(testDisplay[j][i]->getBlue() == 120);
            }
        }


        testLED->setRGB(0, 0, 0);
        testGrid->updateLEDs(0, 0, 3, testLED);
        testGrid->copyDisplayElement(0, 1);
        testGrid->copyDisplayElement(0, 2);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }
    }

    SECTION("Tests setting all LEDs differently") {
        LED *first = new LED();
        LED *second = new LED();
        LED *third = new LED();
        LED *fourth = new LED();
        LED *fifth = new LED();
        LED *sixth = new LED();

        first->setRGB(1, 2, 3);
        second->setRGB(4, 5, 6);
        third->setRGB(7, 8, 9);
        fourth->setRGB(10, 11, 12);
        fifth->setRGB(13, 14, 15);
        sixth->setRGB(16, 17, 18);

        testGrid = new LEDGrid(3, 2);
        testGrid->updateLEDs(0, 0, 1, first);
        testGrid->updateLEDs(1, 0, 1, second);
        testGrid->updateLEDs(0, 1, 1, third);
        testGrid->updateLEDs(1, 1, 1, fourth);
        testGrid->updateLEDs(0, 2, 1, fifth);
        testGrid->updateLEDs(1, 2, 1, sixth);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 2);

        REQUIRE(testDisplay[0][0]->getRed() == 1);
        REQUIRE(testDisplay[0][0]->getGreen() == 2);
        REQUIRE(testDisplay[0][0]->getBlue() == 3);
        REQUIRE(testDisplay[0][1]->getRed() == 4);
        REQUIRE(testDisplay[0][1]->getGreen() == 5);
        REQUIRE(testDisplay[0][1]->getBlue() == 6);
        REQUIRE(testDisplay[1][0]->getRed() == 7);
        REQUIRE(testDisplay[1][0]->getGreen() == 8);
        REQUIRE(testDisplay[1][0]->getBlue() == 9);
        REQUIRE(testDisplay[1][1]->getRed() == 10);
        REQUIRE(testDisplay[1][1]->getGreen() == 11);
        REQUIRE(testDisplay[1][1]->getBlue() == 12);
        REQUIRE(testDisplay[2][0]->getRed() == 13);
        REQUIRE(testDisplay[2][0]->getGreen() == 14);
        REQUIRE(testDisplay[2][0]->getBlue() == 15);
        REQUIRE(testDisplay[2][1]->getRed() == 16);
        REQUIRE(testDisplay[2][1]->getGreen() == 17);
        REQUIRE(testDisplay[2][1]->getBlue() == 18);
        

        testGrid->turnOff();
        altTestDisplay = new LED**[3];
        altTestDisplay[0] = new LED*[2];
        altTestDisplay[1] = new LED*[2];
        altTestDisplay[2] = new LED*[2];
        altTestDisplay[0][0] = first;
        altTestDisplay[0][1] = second;
        altTestDisplay[1][0] = third;
        altTestDisplay[1][1] = fourth;
        altTestDisplay[2][0] = fifth;
        altTestDisplay[2][1] = sixth;
        testGrid->updateDisplay(2, 3, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 2);

        REQUIRE(testDisplay[0][0]->getRed() == 1);
        REQUIRE(testDisplay[0][0]->getGreen() == 2);
        REQUIRE(testDisplay[0][0]->getBlue() == 3);
        REQUIRE(testDisplay[0][1]->getRed() == 4);
        REQUIRE(testDisplay[0][1]->getGreen() == 5);
        REQUIRE(testDisplay[0][1]->getBlue() == 6);
        REQUIRE(testDisplay[1][0]->getRed() == 7);
        REQUIRE(testDisplay[1][0]->getGreen() == 8);
        REQUIRE(testDisplay[1][0]->getBlue() == 9);
        REQUIRE(testDisplay[1][1]->getRed() == 10);
        REQUIRE(testDisplay[1][1]->getGreen() == 11);
        REQUIRE(testDisplay[1][1]->getBlue() == 12);
        REQUIRE(testDisplay[2][0]->getRed() == 13);
        REQUIRE(testDisplay[2][0]->getGreen() == 14);
        REQUIRE(testDisplay[2][0]->getBlue() == 15);
        REQUIRE(testDisplay[2][1]->getRed() == 16);
        REQUIRE(testDisplay[2][1]->getGreen() == 17);
        REQUIRE(testDisplay[2][1]->getBlue() == 18);
    }

    SECTION("Tests inserting a new strip into the grid") {
        testGrid = new LEDGrid(4, 3);
        testStrip = new LEDStrip(4);
        LED *first = new LED();
        LED *second = new LED(); 
        first->setRed(255);
        second->setGreen(255);
        testGrid->updateLEDs(0, 0, 1, first);
        testGrid->updateLEDs(1, 0, 1, second);
        testGrid->updateLEDs(2, 0, 1, second);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 4);
        REQUIRE(testGrid->getWidth() == 3);

        REQUIRE(testDisplay[0][0]->getRed() == 255);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);
        REQUIRE(testDisplay[0][1]->getRed() == 0);
        REQUIRE(testDisplay[0][1]->getGreen() == 255);
        REQUIRE(testDisplay[0][1]->getBlue() == 0);
        REQUIRE(testDisplay[0][2]->getRed() == 0);
        REQUIRE(testDisplay[0][2]->getGreen() == 255);
        REQUIRE(testDisplay[0][2]->getBlue() == 0);
        for(int i = 0; i < 3; i++) {
            for(int j = 1; j < 4; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }
        

        testGrid->getStrip(0)->updateDisplay(4, 1, testGrid->getStrip(1)->getDisplay());
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 4);
        REQUIRE(testGrid->getWidth() == 3);

        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 255);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);
        REQUIRE(testDisplay[0][1]->getRed() == 0);
        REQUIRE(testDisplay[0][1]->getGreen() == 255);
        REQUIRE(testDisplay[0][1]->getBlue() == 0);
        REQUIRE(testDisplay[0][2]->getRed() == 0);
        REQUIRE(testDisplay[0][2]->getGreen() == 255);
        REQUIRE(testDisplay[0][2]->getBlue() == 0);
        for(int i = 0; i < 3; i++) {
            for(int j = 1; j < 4; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }
    }
}

TEST_CASE("Edge LEDgrid test cases") {
    LED *testLED = new LED();
    LEDGrid *altTestGrid;
    LEDGrid *testGrid;
    LED ***altTestDisplay;
    LED ***testDisplay;

    SECTION("Tests modifying a returned display") {
        testLED->setBlue(255);
        testGrid = new LEDGrid(3, 4);
        testGrid->updateLEDs(0, 0, 3, testLED);
        testGrid->updateLEDs(1, 0, 3, testLED);
        testGrid->updateLEDs(2, 0, 3, testLED);
        testGrid->updateLEDs(3, 0, 3, testLED);
        testDisplay = testGrid->getDisplay();
        
        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 4);

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 255);
            }
        }


        testLED->setRGB(255, 255, 0);
        testDisplay = testGrid->getDisplay();
        
        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 4);

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 255);
            }
        }
    }

    SECTION("Tests updating the grid with a smaller display") {
        testLED->setBlue(255);
        testGrid = new LEDGrid(3, 4);
        testGrid->updateLEDs(0, 0, 3, testLED);
        testGrid->updateLEDs(1, 0, 3, testLED);
        testGrid->updateLEDs(2, 0, 3, testLED);
        testGrid->updateLEDs(3, 0, 3, testLED);

        altTestGrid = new LEDGrid(2, 2);
        testGrid->updateDisplay(2, 2, altTestGrid->getDisplay());
        testDisplay = testGrid->getDisplay();
        
        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 4);

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                if(i < 2 && j < 2) {
                    REQUIRE(testDisplay[j][i]->getRed() == 0);
                    REQUIRE(testDisplay[j][i]->getGreen() == 0);
                    REQUIRE(testDisplay[j][i]->getBlue() == 0);
                }
                else {
                    REQUIRE(testDisplay[j][i]->getRed() == 0);
                    REQUIRE(testDisplay[j][i]->getGreen() == 0);
                    REQUIRE(testDisplay[j][i]->getBlue() == 255);
                }
            }
        }
    }

    SECTION("Tests an LED grid with only one LED") {
        testGrid = new LEDGrid(1, 1);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 1);
        REQUIRE(testGrid->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);


        testGrid->turnOff();
        testDisplay = testGrid->getDisplay();
        REQUIRE(testGrid->getHeight() == 1);
        REQUIRE(testGrid->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);


        testGrid->copyDisplayElement(0, 0);
        testDisplay = testGrid->getDisplay();
        REQUIRE(testGrid->getHeight() == 1);
        REQUIRE(testGrid->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);


        testLED->setRGB(90, 80, 0);
        testGrid->updateLEDs(0, 0, 1, testLED);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 1);
        REQUIRE(testGrid->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 90);
        REQUIRE(testDisplay[0][0]->getGreen() == 80);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);


        testLED->setRGB(0, 1, 0);
        altTestDisplay = new LED**[1];
        altTestDisplay[0] = new LED*[1];
        altTestDisplay[0][0] = testLED;
        testGrid->updateDisplay(1, 1, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 1);
        REQUIRE(testGrid->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 1);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);
    
    }
}

TEST_CASE("Empty LEDgrid test cases") {
    LED *testLED = new LED();
    LEDGrid *testGrid;
    LED ***altTestDisplay;
    LED ***testDisplay;

    SECTION("Tests using null values to update individual LEDs in a grid") {
        testGrid = new LEDGrid(3, 3);
        testLED->setRGB(5, 6, 7);
        testGrid->updateLEDs(0, 0, 3, testLED);
        testGrid->updateLEDs(1, 0, 3, testLED);
        testGrid->updateLEDs(2, 0, 3, testLED);
        testGrid->updateDisplay(3, 3, nullptr);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 5);
                REQUIRE(testDisplay[j][i]->getGreen() == 6);
                REQUIRE(testDisplay[j][i]->getBlue() == 7);
            }
        }


        altTestDisplay = new LED**[3];
        for(int i = 0; i < 3; i++) {
            altTestDisplay[i] = new LED*[3];

            for(int j = 0; j < 3; j++) {
                altTestDisplay[i][j] = nullptr;
            }
        }

        testGrid->updateDisplay(3, 3, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 5);
                REQUIRE(testDisplay[j][i]->getGreen() == 6);
                REQUIRE(testDisplay[j][i]->getBlue() == 7);
            }
        }


        for(int i = 0; i < 3; i++) {
            for(int j = 1; j < 3; j++) {
                altTestDisplay[j][i] = new LED();
            }
        }
        testGrid->updateDisplay(3, 3, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        REQUIRE(testDisplay[0][0]->getRed() == 5);
        REQUIRE(testDisplay[0][0]->getGreen() == 6);
        REQUIRE(testDisplay[0][0]->getBlue() == 7);
        REQUIRE(testDisplay[0][1]->getRed() == 5);
        REQUIRE(testDisplay[0][1]->getGreen() == 6);
        REQUIRE(testDisplay[0][1]->getBlue() == 7);
        REQUIRE(testDisplay[0][2]->getRed() == 5);
        REQUIRE(testDisplay[0][2]->getGreen() == 6);
        REQUIRE(testDisplay[0][2]->getBlue() == 7);
        for(int i = 0; i < 3; i++) {
            for(int j = 1; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }
    }

    SECTION("Tests using null values to update the grid") {
        testGrid = new LEDGrid(3, 3);
        testLED->setRGB(5, 6, 7);
        testGrid->updateLEDs(0, 0, 3, testLED);
        testGrid->updateLEDs(1, 0, 3, testLED);
        testGrid->updateLEDs(2, 0, 3, testLED);
        testGrid->updateDisplay(3, 3, nullptr);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; i < 3; i++) {
                REQUIRE(testDisplay[i][j]->getRed() == 5);
                REQUIRE(testDisplay[i][j]->getGreen() == 6);
                REQUIRE(testDisplay[i][j]->getBlue() == 7);
            }
        }


        altTestDisplay = new LED**[3];
        altTestDisplay[0] = new LED*[3];
        altTestDisplay[1] = new LED*[3];
        altTestDisplay[2] = new LED*[3];

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                altTestDisplay[j][i] = nullptr;
            }
        }

        testGrid->updateDisplay(3, 3, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 5);
                REQUIRE(testDisplay[j][i]->getGreen() == 6);
                REQUIRE(testDisplay[j][i]->getBlue() == 7);
            }
        }


        testLED->setRGB(200, 201, 195);
        altTestDisplay[0][0] = testLED;
        altTestDisplay[0][1] = testLED;
        altTestDisplay[0][2] = testLED;
        testGrid->updateDisplay(3, 3, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        REQUIRE(testDisplay[0][0]->getRed() == 200);
        REQUIRE(testDisplay[0][0]->getGreen() == 201);
        REQUIRE(testDisplay[0][0]->getBlue() == 195);
        REQUIRE(testDisplay[0][1]->getRed() == 200);
        REQUIRE(testDisplay[0][1]->getGreen() == 201);
        REQUIRE(testDisplay[0][1]->getBlue() == 195);
        REQUIRE(testDisplay[0][2]->getRed() == 200);
        REQUIRE(testDisplay[0][2]->getGreen() == 201);
        REQUIRE(testDisplay[0][2]->getBlue() == 195);
        for(int i = 0; i < 3; i++) {
            for(int j = 1; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 5);
                REQUIRE(testDisplay[j][i]->getGreen() == 6);
                REQUIRE(testDisplay[j][i]->getBlue() == 7);
            }
        }
    }
}

TEST_CASE("Invalid LEDgrid test cases") {
    LED *testLED = new LED();
    LEDGrid *testGrid;
    LED ***altTestDisplay;
    LED ***testDisplay;

    SECTION("Tests modifying invalid lengths of a grid") {
        testLED->setRGB(5, 6, 7);
        testGrid = new LEDGrid(3, 3);
        altTestDisplay = new LED**[5];
        for(int i = 0; i < 5; i++) {
            altTestDisplay[i] = new LED*[1];
            altTestDisplay[i][0] = testLED;
        }

        testGrid->updateDisplay(5, 1, altTestDisplay);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testGrid->updateLEDs(0, 0, 300, testLED);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }

    SECTION("Tests trying to access and modify invalid position of a grid") {
        testLED->setRGB(5, 10, 15);
        testGrid = new LEDGrid(3, 3);
        testGrid->copyDisplayElement(-1, 1);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        testGrid->copyDisplayElement(5, -1);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        testGrid->copyDisplayElement(100, 5);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        testGrid->copyDisplayElement(5, 100);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        testGrid->updateLEDs(0, -1, 11, testLED);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        testGrid->updateLEDs(0, 100, 11, testLED);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        testGrid->updateLEDs(-1, 0, 11, testLED);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }


        testLED->setRGB(0, 0, 0);
        testGrid->updateLEDs(100, 0, 11, testLED);
        testDisplay = testGrid->getDisplay();

        REQUIRE(testGrid->getHeight() == 3);
        REQUIRE(testGrid->getWidth() == 3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                REQUIRE(testDisplay[j][i]->getRed() == 0);
                REQUIRE(testDisplay[j][i]->getGreen() == 0);
                REQUIRE(testDisplay[j][i]->getBlue() == 0);
            }
        }
    }
}