#include "../../src/Objects/LEDStrip.h"
#include "../../src/Objects/LED.h"
#include "../catch.hpp"

TEST_CASE("Basic LEDStrip test cases") {
    SECTION("Testing default values") {
        LEDStrip *testStrip;
        LED ***testDisplay;

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
        LED *testLED = new LED();
        LEDStrip *testStrip;
        LED ***testDisplay;
        
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


        LEDStrip *altTestStrip = new LEDStrip(4);
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
    SECTION("Tests modifying multiple LEDs") {
        LED *testLED = new LED();
        LEDStrip *testStrip;
        LED ***testDisplay;
        
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


        LEDStrip *altTestStrip = new LEDStrip(5);
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
        LED *testLED = new LED();
        LEDStrip *testStrip;
        LED ***testDisplay;
        
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


        LEDStrip *altTestStrip = new LEDStrip(4);
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
        LED *testLED = new LED();
        LEDStrip *testStrip;
        LED ***testDisplay;
        
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


        LEDStrip *altTestStrip = new LEDStrip(7);
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
        LEDStrip *testStrip;
        LED ***testDisplay;

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

        LEDStrip *altTestStrip = new LEDStrip(2);
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
    SECTION("Tests modifying a strip when a non zero width is specified") {
        LED *testLED = new LED();
        LEDStrip *testStrip;
        LED ***testDisplay;
            
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
        LED *testLED = new LED();
        LEDStrip *testStrip;
        LED ***testDisplay;
        
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
        LED *testLED = new LED();
        LEDStrip *testStrip;
        LED ***testDisplay;
        
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


        LEDStrip *altTestStrip = new LEDStrip(6);
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
        LED *testLED = new LED();
        LEDStrip *testStrip;
        LED ***testDisplay;
        
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


        LEDStrip *altTestStrip = new LEDStrip(3);
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

    //set display with too small of values

    //set with only 1
}

TEST_CASE("Empty LEDStrip test cases") {
    SECTION("Tests using null values to update individual LEDs in a strip") {
        LED *testLED = new LED();
        LEDStrip *testStrip;
        LED ***testDisplay;
        
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
        LED *testLED = new LED();
        LEDStrip *testStrip;
        LED ***testDisplay;
        
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


        LED ***altTestDisplay = new LED**[3];
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
    SECTION("Tests setting invalid lengths of a strip") {

    }

    SECTION("Tests trying to access and modify invalid position of a strip") {
        //too large
        //negative
    }
}