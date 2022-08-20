#define CATCH_CONFIG_MAIN

#include "../../src/Objects/LED.h"
#include "../catch.hpp"


TEST_CASE("Basic LED test cases") {
    LED *testLED;

    SECTION("Default RGB values") {
        testLED = new LED();
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 0);
    }

    SECTION("Tests setting basic RGB values") {
        testLED = new LED();
        testLED->setRed(5);
        REQUIRE(testLED->getRed() == 5);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 0);

        testLED = new LED();
        testLED->setGreen(5);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 5);
        REQUIRE(testLED->getBlue() == 0);

        testLED = new LED();
        testLED->setBlue(5);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 5);

        testLED = new LED();
        testLED->setRGB(8, 9, 10);
        REQUIRE(testLED->getRed() == 8);
        REQUIRE(testLED->getGreen() == 9);
        REQUIRE(testLED->getBlue() == 10);
    }
}

TEST_CASE("More complex LED test cases") {
    LED *testLED;

    SECTION("Tests setting larger RGB values") {
        testLED = new LED();
        testLED->setRed(150);
        REQUIRE(testLED->getRed() == 150);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 0);

        testLED = new LED();
        testLED->setGreen(150);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 150);
        REQUIRE(testLED->getBlue() == 0);

        testLED = new LED();
        testLED->setBlue(150);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 150);

        testLED = new LED();
        testLED->setRGB(150, 151, 152);
        REQUIRE(testLED->getRed() == 150);
        REQUIRE(testLED->getGreen() == 151);
        REQUIRE(testLED->getBlue() == 152);
    }

    SECTION("Tests resetting RGB after previously setting them") {
        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRed(150);
        REQUIRE(testLED->getRed() == 150);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setGreen(150);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 150);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setBlue(150);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 150);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRGB(150, 151, 152);
        REQUIRE(testLED->getRed() == 150);
        REQUIRE(testLED->getGreen() == 151);
        REQUIRE(testLED->getBlue() == 152);
    }
}

TEST_CASE("Edge LED test cases") {
    LED *testLED;

    SECTION("Tests setting edge RGB values") {
        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRed(255);
        REQUIRE(testLED->getRed() == 255);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setGreen(255);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 255);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setBlue(255);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 255);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRGB(255, 255, 255);
        REQUIRE(testLED->getRed() == 255);
        REQUIRE(testLED->getGreen() == 255);
        REQUIRE(testLED->getBlue() == 255);
        
        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRed(0);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setGreen(0);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setBlue(0);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 0);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRGB(0, 0, 0);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 0);
    }

    SECTION("Tests setting duplicate RGB values") {
        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRed(10);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setGreen(20);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setBlue(30);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRGB(10, 20, 30);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 30);
        
        testLED = new LED();
        testLED->setRed(0);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 0);

        testLED = new LED();
        testLED->setGreen(0);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 0);

        testLED = new LED();
        testLED->setBlue(0);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 0);

        testLED = new LED();
        testLED->setRGB(0, 0, 0);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 0);
    }    
}

TEST_CASE("Invalid LED test cases") {
    LED *testLED;
    
    SECTION("Tests normalizing RGB values") {
        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRed(-150);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setGreen(-150);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setBlue(-150);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 0);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRGB(-150, -151, -152);
        REQUIRE(testLED->getRed() == 0);
        REQUIRE(testLED->getGreen() == 0);
        REQUIRE(testLED->getBlue() == 0);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRed(500);
        REQUIRE(testLED->getRed() == 255);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setGreen(500);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 255);
        REQUIRE(testLED->getBlue() == 30);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setBlue(500);
        REQUIRE(testLED->getRed() == 10);
        REQUIRE(testLED->getGreen() == 20);
        REQUIRE(testLED->getBlue() == 255);

        testLED = new LED();
        testLED->setRGB(10, 20, 30);
        testLED->setRGB(500, 600, 400);
        REQUIRE(testLED->getRed() == 255);
        REQUIRE(testLED->getGreen() == 255);
        REQUIRE(testLED->getBlue() == 255);
    }
}