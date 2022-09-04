#include "../../src/Objects/LEDStrip.h"
#include "../../src/Objects/LED.h"
#include "../catch.hpp"

TEST_CASE("Basic LEDStrip test cases") {
    LED *testLED = new LED();
    LEDStrip *altTestStrip;
    LEDStrip *testStrip;
    LED ***testDisplay;

    SECTION("Testing default values") {
        testStrip = new LEDStrip(5);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 5);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 5; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }

    SECTION("Testing changing a single LED") {
        testStrip = new LEDStrip(4);
        testLED->setRGB(5, 6, 7);
        testStrip->updateLEDs(0, 1, 1, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 4);
        REQUIRE(testStrip->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);
        REQUIRE(testDisplay[1][0]->getRed() == 5);
        REQUIRE(testDisplay[1][0]->getGreen() == 6);
        REQUIRE(testDisplay[1][0]->getBlue() == 7);
        for(int i = 2; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->turnOff();
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 4);
        REQUIRE(testStrip->getWidth() == 1);
        
        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        altTestStrip = new LEDStrip(4);
        altTestStrip->updateLEDs(0, 1, 1, testLED);
        testStrip->updateDisplay(altTestStrip->getHeight(), altTestStrip->getWidth(), altTestStrip->getDisplay());
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 4);
        REQUIRE(testStrip->getWidth() == 1);
       
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);
        REQUIRE(testDisplay[1][0]->getRed() == 5);
        REQUIRE(testDisplay[1][0]->getGreen() == 6);
        REQUIRE(testDisplay[1][0]->getBlue() == 7); 
        for(int i = 2; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->copyDisplayElement(2, 1);
        testDisplay = testStrip->getDisplay();
                
        REQUIRE(testStrip->getHeight() == 4);
        REQUIRE(testStrip->getWidth() == 1);
        
        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }
}

TEST_CASE("More complex LEDStrip test cases") {
    LED *testLED = new LED();
    LEDStrip *altTestStrip;
    LEDStrip *testStrip;
    LED ***testDisplay;

    SECTION("Tests modifying multiple LEDs") {        
        testStrip = new LEDStrip(5);
        testLED->setRGB(5, 6, 7);
        testStrip->updateLEDs(0, 1, 1, testLED);
        testStrip->updateLEDs(0, 3, 2, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 5);
        REQUIRE(testStrip->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);
        REQUIRE(testDisplay[1][0]->getRed() == 5);
        REQUIRE(testDisplay[1][0]->getGreen() == 6);
        REQUIRE(testDisplay[1][0]->getBlue() == 7);
        REQUIRE(testDisplay[2][0]->getRed() == 0);
        REQUIRE(testDisplay[2][0]->getGreen() == 0);
        REQUIRE(testDisplay[2][0]->getBlue() == 0);
        for(int i = 3; i < 5; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }


        testStrip->turnOff();
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 5);
        REQUIRE(testStrip->getWidth() == 1);
        
        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        altTestStrip = new LEDStrip(5);
        altTestStrip->updateLEDs(0, 1, 1, testLED);
        altTestStrip->updateLEDs(0, 3, 2, testLED);
        testStrip->updateDisplay(altTestStrip->getHeight(), altTestStrip->getWidth(), altTestStrip->getDisplay());
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 5);
        REQUIRE(testStrip->getWidth() == 1);
       
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);
        REQUIRE(testDisplay[1][0]->getRed() == 5);
        REQUIRE(testDisplay[1][0]->getGreen() == 6);
        REQUIRE(testDisplay[1][0]->getBlue() == 7);
        REQUIRE(testDisplay[2][0]->getRed() == 0);
        REQUIRE(testDisplay[2][0]->getGreen() == 0);
        REQUIRE(testDisplay[2][0]->getBlue() == 0);
        for(int i = 3; i < 5; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }


        testStrip->copyDisplayElement(2, 1);
        testStrip->copyDisplayElement(2, 4);
        testDisplay = testStrip->getDisplay();
                
        REQUIRE(testStrip->getHeight() == 5);
        REQUIRE(testStrip->getWidth() == 1);
        
        for(int i = 0; i < 3; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
        REQUIRE(testDisplay[3][0]->getRed() == 5);
        REQUIRE(testDisplay[3][0]->getGreen() == 6);
        REQUIRE(testDisplay[3][0]->getBlue() == 7);
        REQUIRE(testDisplay[4][0]->getRed() == 0);
        REQUIRE(testDisplay[4][0]->getGreen() == 0);
        REQUIRE(testDisplay[4][0]->getBlue() == 0);

        testStrip->copyDisplayElement(1, 3);
        testDisplay = testStrip->getDisplay();
                
        REQUIRE(testStrip->getHeight() == 5);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }

    SECTION("Tests modifying all LEDs when there is an even amount") {
        testStrip = new LEDStrip(4);
        testLED->setRGB(5, 6, 7);
        testStrip->updateLEDs(0, 0, 4, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 4);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }


        testStrip->turnOff();
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 4);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        altTestStrip = new LEDStrip(4);
        altTestStrip->updateLEDs(0, 0, 4, testLED);
        testStrip->updateDisplay(altTestStrip->getHeight(), altTestStrip->getWidth(), altTestStrip->getDisplay());
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 4);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }

        testLED->setRGB(0, 0, 0);

        REQUIRE(testStrip->getHeight() == 4);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }

        altTestStrip->updateLEDs(0, 1, 1, testLED);
        altTestStrip->copyDisplayElement(1, 0);
        altTestStrip->copyDisplayElement(1, 2);
        altTestStrip->copyDisplayElement(1, 3);
        testDisplay = altTestStrip->getDisplay();
                
        REQUIRE(testStrip->getHeight() == 4);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }

        testStrip->updateDisplay(altTestStrip->getHeight(), altTestStrip->getWidth(), testDisplay);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 4);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }

    SECTION("Tests modifying all LEDs when there is an odd amount") {
        testStrip = new LEDStrip(7);
        testLED->setRGB(5, 6, 7);
        testStrip->updateLEDs(0, 0, 7, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 7);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 7; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }


        testStrip->turnOff();
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 7);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 7; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        altTestStrip = new LEDStrip(7);
        altTestStrip->updateLEDs(0, 0, 7, testLED);
        testStrip->updateDisplay(altTestStrip->getHeight(), altTestStrip->getWidth(), altTestStrip->getDisplay());
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 7);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 7; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }

        testLED->setRGB(0, 0, 0);

        REQUIRE(testStrip->getHeight() == 7);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 7; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }

        altTestStrip->updateLEDs(0, 1, 1, testLED);
        altTestStrip->copyDisplayElement(1, 0);
        altTestStrip->copyDisplayElement(1, 2);
        altTestStrip->copyDisplayElement(1, 3);
        altTestStrip->copyDisplayElement(1, 4);
        altTestStrip->copyDisplayElement(1, 5);
        altTestStrip->copyDisplayElement(1, 6);
        testDisplay = altTestStrip->getDisplay();
                
        REQUIRE(testStrip->getHeight() == 7);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 7; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }

        testStrip->updateDisplay(altTestStrip->getHeight(), altTestStrip->getWidth(), testDisplay);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 7);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 7; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }

    SECTION("Tests setting all LEDs differently") {
        LED *first = new LED();
        LED *second = new LED();

        testStrip = new LEDStrip(2);
        first->setRGB(5, 6, 7);
        second->setRGB(10, 11, 12);
        testStrip->updateLEDs(0, 0, 1, first);
        testStrip->updateLEDs(0, 1, 1, second);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 2);
        REQUIRE(testStrip->getWidth() == 1);

        REQUIRE(testDisplay[0][0]->getRed() == 5);
        REQUIRE(testDisplay[0][0]->getGreen() == 6);
        REQUIRE(testDisplay[0][0]->getBlue() == 7);
        REQUIRE(testDisplay[1][0]->getRed() == 10);
        REQUIRE(testDisplay[1][0]->getGreen() == 11);
        REQUIRE(testDisplay[1][0]->getBlue() == 12);

        altTestStrip = new LEDStrip(2);
        altTestStrip->updateLEDs(0, 0, 1, second);
        altTestStrip->updateLEDs(0, 1, 1, first);

        testStrip->updateDisplay(altTestStrip->getHeight(), altTestStrip->getWidth(), altTestStrip->getDisplay());
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 2);
        REQUIRE(testStrip->getWidth() == 1);

        REQUIRE(testDisplay[0][0]->getRed() == 10);
        REQUIRE(testDisplay[0][0]->getGreen() == 11);
        REQUIRE(testDisplay[0][0]->getBlue() == 12);
        REQUIRE(testDisplay[1][0]->getRed() == 5);
        REQUIRE(testDisplay[1][0]->getGreen() == 6);
        REQUIRE(testDisplay[1][0]->getBlue() == 7);
    }
}

TEST_CASE("Edge LEDStrip test cases") {
    LED *testLED = new LED();
    LEDStrip *altTestStrip;
    LEDStrip *testStrip;
    LED ***altTestDisplay;
    LED ***testDisplay;

    SECTION("Tests modifying a strip when a non zero width is specified") {            
        testStrip = new LEDStrip(8);
        testLED->setRGB(5, 6, 7);
        testStrip->updateLEDs(2, 0, 1, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 8);
        REQUIRE(testStrip->getWidth() == 1);

        REQUIRE(testDisplay[0][0]->getRed() == 5);
        REQUIRE(testDisplay[0][0]->getGreen() == 6);
        REQUIRE(testDisplay[0][0]->getBlue() == 7);
        for(int i = 1; i < 8; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }

    SECTION("Tests modifying a returned display") {        
        testStrip = new LEDStrip(3);
        testLED->setRGB(5, 6, 7);
        testDisplay = testStrip->getDisplay();

        testDisplay[0][0] = testLED;
        testDisplay[1][0] = testLED;
        testDisplay[2][0] = testLED;

        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);
        
        for(int i = 0; i < 3; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }

    SECTION("Tests modifying only the first LED in the strip") {
        testStrip = new LEDStrip(6);
        testLED->setRGB(5, 6, 7);
        testStrip->updateLEDs(0, 0, 1, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 6);
        REQUIRE(testStrip->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 5);
        REQUIRE(testDisplay[0][0]->getGreen() == 6);
        REQUIRE(testDisplay[0][0]->getBlue() == 7);
        for(int i = 1; i < 6; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->turnOff();
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 6);
        REQUIRE(testStrip->getWidth() == 1);
        
        for(int i = 0; i < 4; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        altTestStrip = new LEDStrip(6);
        altTestStrip->updateLEDs(0, 0, 1, testLED);
        testStrip->updateDisplay(altTestStrip->getHeight(), altTestStrip->getWidth(), altTestStrip->getDisplay());
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 6);
        REQUIRE(testStrip->getWidth() == 1);
       
        REQUIRE(testDisplay[0][0]->getRed() == 5);
        REQUIRE(testDisplay[0][0]->getGreen() == 6);
        REQUIRE(testDisplay[0][0]->getBlue() == 7); 
        for(int i = 1; i < 6; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->copyDisplayElement(1, 0);
        testDisplay = testStrip->getDisplay();
                
        REQUIRE(testStrip->getHeight() == 6);
        REQUIRE(testStrip->getWidth() == 1);
        
        for(int i = 0; i < 6; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }

    SECTION("Tests modifying only the last LED in the strip") {
        testStrip = new LEDStrip(3);
        testLED->setRGB(5, 6, 7);
        testStrip->updateLEDs(0, 2, 1, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 1; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
        REQUIRE(testDisplay[2][0]->getRed() == 5);
        REQUIRE(testDisplay[2][0]->getGreen() == 6);
        REQUIRE(testDisplay[2][0]->getBlue() == 7);


        testStrip->turnOff();
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);
        
        for(int i = 0; i < 3; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        altTestStrip = new LEDStrip(3);
        altTestStrip->updateLEDs(0, 2, 1, testLED);
        testStrip->updateDisplay(altTestStrip->getHeight(), altTestStrip->getWidth(), altTestStrip->getDisplay());
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);
       
        for(int i = 0; i < 1; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
        REQUIRE(testDisplay[2][0]->getRed() == 5);
        REQUIRE(testDisplay[2][0]->getGreen() == 6);
        REQUIRE(testDisplay[2][0]->getBlue() == 7);


        testStrip->copyDisplayElement(0, 2);
        testDisplay = testStrip->getDisplay();
                
        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);
        
        for(int i = 0; i < 3; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }

    SECTION("Tests updating the strip with a smaller display") {
        testStrip = new LEDStrip(10);
        testLED->setRGB(15, 255, 13);

        LED ***altTestDisplay = new LED**[2];
        altTestDisplay[0] = new LED*[1];
        altTestDisplay[1] = new LED*[1];
        altTestDisplay[0][0] = testLED;
        altTestDisplay[1][0] = testLED;
        
        testStrip->updateDisplay(2, 1, altTestDisplay);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 10);
        REQUIRE(testStrip->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 15);
        REQUIRE(testDisplay[0][0]->getGreen() == 255);
        REQUIRE(testDisplay[0][0]->getBlue() == 13);
        REQUIRE(testDisplay[1][0]->getRed() == 15);
        REQUIRE(testDisplay[1][0]->getGreen() == 255);
        REQUIRE(testDisplay[1][0]->getBlue() == 13);
        for(int i = 2; i < 10; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }

    SECTION("Tests an LED strip with only one LED") {
        testStrip = new LEDStrip(1);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 1);
        REQUIRE(testStrip->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);


        testStrip->turnOff();
        testDisplay = testStrip->getDisplay();
        REQUIRE(testStrip->getHeight() == 1);
        REQUIRE(testStrip->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);


        testStrip->copyDisplayElement(0, 0);
        testDisplay = testStrip->getDisplay();
        REQUIRE(testStrip->getHeight() == 1);
        REQUIRE(testStrip->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 0);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);


        testLED->setRGB(90, 80, 0);
        testStrip->updateLEDs(0, 0, 1, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 1);
        REQUIRE(testStrip->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 90);
        REQUIRE(testDisplay[0][0]->getGreen() == 80);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);


        testLED->setRGB(0, 1, 0);
        altTestDisplay = new LED**[1];
        altTestDisplay[0] = new LED*[1];
        altTestDisplay[0][0] = testLED;
        testStrip->updateDisplay(1, 1, altTestDisplay);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 1);
        REQUIRE(testStrip->getWidth() == 1);
        
        REQUIRE(testDisplay[0][0]->getRed() == 0);
        REQUIRE(testDisplay[0][0]->getGreen() == 1);
        REQUIRE(testDisplay[0][0]->getBlue() == 0);
    }
}

TEST_CASE("Empty LEDStrip test cases") {
    LED *testLED = new LED();
    LEDStrip *testStrip;
    LED ***altTestDisplay;
    LED ***testDisplay;

    SECTION("Tests using null values to update individual LEDs in a strip") {
        testStrip = new LEDStrip(3);
        testLED->setRGB(5, 6, 7);
        testStrip->updateLEDs(0, 0, 3, testLED);
        testDisplay = testStrip->getDisplay();

        testStrip->updateLEDs(0, 1, 1, nullptr);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 3; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }


        testStrip->updateLEDs(0, 0, 3, nullptr);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 3; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }
    }

    SECTION("Tests using null values to update the strip") {        
        testStrip = new LEDStrip(3);
        testLED->setRGB(5, 6, 7);
        testStrip->updateLEDs(0, 0, 3, testLED);
        testStrip->updateDisplay(3, 1, nullptr);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 3; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }


        altTestDisplay = new LED**[3];
        altTestDisplay[0] = new LED*[1];
        altTestDisplay[1] = new LED*[1];
        altTestDisplay[2] = new LED*[1];

        altTestDisplay[0][0] = nullptr;
        altTestDisplay[1][0] = nullptr;
        altTestDisplay[2][0] = nullptr;

        testStrip->updateDisplay(3, 1, altTestDisplay);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 3; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }

        testLED->setRGB(200, 201, 195);
        altTestDisplay[1][0] = testLED;
        testStrip->updateDisplay(3, 1, altTestDisplay);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);

        REQUIRE(testDisplay[0][0]->getRed() == 5);
        REQUIRE(testDisplay[0][0]->getGreen() == 6);
        REQUIRE(testDisplay[0][0]->getBlue() == 7);
        REQUIRE(testDisplay[1][0]->getRed() == 200);
        REQUIRE(testDisplay[1][0]->getGreen() == 201);
        REQUIRE(testDisplay[1][0]->getBlue() == 195);
        REQUIRE(testDisplay[2][0]->getRed() == 5);
        REQUIRE(testDisplay[2][0]->getGreen() == 6);
        REQUIRE(testDisplay[2][0]->getBlue() == 7);
    }
}

TEST_CASE("Invalid LEDStrip test cases") {
    LED *testLED = new LED();
    LEDStrip *testStrip;
    LED ***testAltDisplay;
    LED ***testDisplay;

    SECTION("Tests modifying invalid lengths of a strip") {
        testLED->setRGB(5, 6, 7);
        testStrip = new LEDStrip(3);
        testAltDisplay = new LED**[5];
        for(int i = 0; i < 5; i++) {
            testAltDisplay[i] = new LED*[1];
            testAltDisplay[i][0] = testLED;
        }

        testStrip->updateDisplay(5, 1, testAltDisplay);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 3; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->updateLEDs(100, 0, 300, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 3; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->updateLEDs(0, 0, 3, testLED);
        testLED->setRGB(100, 100, 100);
        testStrip->updateLEDs(100, 0, 300, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 3);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 3; i++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 6);
            REQUIRE(testDisplay[i][0]->getBlue() == 7);
        }
    }

    SECTION("Tests trying to access and modify invalid position of a strip") {
        testLED->setRGB(5, 10, 15);
        testStrip = new LEDStrip(11);
        testStrip->copyDisplayElement(-1, 5);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 11);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 11; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->copyDisplayElement(5, -1);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 11);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 11; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->copyDisplayElement(100, 5);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 11);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 11; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->copyDisplayElement(5, 100);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 11);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 11; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->updateLEDs(0, -1, 11, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 11);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 11; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->updateLEDs(0, 100, 11, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 11);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 11; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }


        testStrip->updateLEDs(-1, 0, 11, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 11);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 11; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 5);
            REQUIRE(testDisplay[i][0]->getGreen() == 10);
            REQUIRE(testDisplay[i][0]->getBlue() == 15);
        }


        testLED->setRGB(0, 0, 0);
        testStrip->updateLEDs(100, 0, 11, testLED);
        testDisplay = testStrip->getDisplay();

        REQUIRE(testStrip->getHeight() == 11);
        REQUIRE(testStrip->getWidth() == 1);

        for(int i = 0; i < 11; i ++) {
            REQUIRE(testDisplay[i][0]->getRed() == 0);
            REQUIRE(testDisplay[i][0]->getGreen() == 0);
            REQUIRE(testDisplay[i][0]->getBlue() == 0);
        }
    }
}