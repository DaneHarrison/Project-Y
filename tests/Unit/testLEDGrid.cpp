#include "../../src/Objects/LEDGrid.h"
#include "../../src/Objects/LED.h"
#include "../catch.hpp"

LED ***create5By5LEDGrid(bool); //test where not symmetrical grid

TEST_CASE("Basic LEDGrid test cases") {
    // LEDGrid *testGrid;
    // LED ***testDisplay;

    // SECTION("Testing default values") {
    //     testGrid = new LEDGrid(5, 5);
    //     testDisplay = testGrid->getDisplay();
        
    //     REQUIRE(testGrid->getHeight() == 5);
    //     REQUIRE(testGrid->getWidth() == 5);

    //     for(int i = 0; i < 5; i++) {
    //         for(int j = 0; j < 5; j++) {
    //             REQUIRE(dynamic_cast<LED*>(testDisplay[i][j]));
    //             REQUIRE(testDisplay[i][j]->getRed() == 0);
    //             REQUIRE(testDisplay[i][j]->getGreen() == 0);
    //             REQUIRE(testDisplay[i][j]->getBlue() == 0);
    //         }
    //     }
    // }
}
//     SECTION("Testing changing entire display") {
//         LED ***activeDisplay = create5By5LEDGrid(false);
//         testGrid = new LEDGrid(5, 5);
//         testGrid->updateDisplay(5, 5, activeDisplay);
//         testDisplay = testGrid->getDisplay();

//         for(int i = 0; i < 5; i ++) {
//             for(int j = 0; j < 5; j++) {
//                 REQUIRE(testDisplay[i][j]->getRed() == 170);
//                 REQUIRE(testDisplay[i][j]->getGreen() == 152);
//                 REQUIRE(testDisplay[i][j]->getBlue() == 169);
//             }
//         }
//     }
// }

// TEST_CASE("More complex LEDGrid test cases") {

// }

// TEST_CASE("Edge LEDGrid test cases") {
//     LEDGrid *testGrid;
//     LED ***testDisplay;

//     SECTION("Testing turning all LEDs off when they are already off") {
//         testGrid = new LEDGrid(5, 5);
//         testGrid->turnOff();
//         testDisplay = testGrid->getDisplay();
        
//         for(int i = 0; i < 5; i++) {
//             for(int j = 0; j < 5; j++) {
//                 REQUIRE(dynamic_cast<LED*>(testDisplay[i][j]));
//                 REQUIRE(testDisplay[i][j]->getRed() == 0);
//                 REQUIRE(testDisplay[i][j]->getGreen() == 0);
//                 REQUIRE(testDisplay[i][j]->getBlue() == 0);
//             }
//         }
//     }
// }

// TEST_CASE("Empty LEDGrid test cases") {
//     LEDGrid *testGrid;
//     LED ***testDisplay;
    
//     SECTION("Testing changing entire display with a nullptr") {
//         LED ***activeDisplay;
//         testGrid = new LEDGrid(5, 5);
//         testGrid->updateDisplay(5, 5, nullptr);
//         testDisplay = testGrid->getDisplay();

//         for(int i = 0; i < 5; i ++) {
//             for(int j = 0; j < 5; j++) {
//                 REQUIRE(testDisplay[i][j]->getRed() == 0);
//                 REQUIRE(testDisplay[i][j]->getGreen() == 0);
//                 REQUIRE(testDisplay[i][j]->getBlue() == 0);
//             }
//         }

//         activeDisplay = create5By5LEDGrid(false);
//         activeDisplay[0] = nullptr;
//         testGrid = new LEDGrid(5, 5);
//         testGrid->updateDisplay(5, 5, activeDisplay);
//         testDisplay = testGrid->getDisplay();

//         for(int i = 0; i < 5; i ++) {
//             for(int j = 0; j < 5; j++) {
//                 REQUIRE(testDisplay[i][j]->getRed() == 0);
//                 REQUIRE(testDisplay[i][j]->getGreen() == 0);
//                 REQUIRE(testDisplay[i][j]->getBlue() == 0);
//             }
//         }

//         activeDisplay = create5By5LEDGrid(false);
//         activeDisplay[0][0] = nullptr;
//         testGrid = new LEDGrid(5, 5); //contains null ptr
//         testGrid->updateDisplay(5, 5, nullptr);
//         testDisplay = testGrid->getDisplay();

//         for(int i = 0; i < 5; i ++) {
//             for(int j = 0; j < 5; j++) {
//                 REQUIRE(testDisplay[i][j]->getRed() == 0);
//                 REQUIRE(testDisplay[i][j]->getGreen() == 0);
//                 REQUIRE(testDisplay[i][j]->getBlue() == 0);
//             }
//         }

//         activeDisplay = create5By5LEDGrid(false);
//         activeDisplay[4][4] = nullptr;
//         testGrid = new LEDGrid(5, 5); //contains null ptr
//         testGrid->updateDisplay(5, 5, nullptr);
//         testDisplay = testGrid->getDisplay();

//         for(int i = 0; i < 5; i ++) {
//             for(int j = 0; j < 5; j++) {
//                 REQUIRE(testDisplay[i][j]->getRed() == 0);
//                 REQUIRE(testDisplay[i][j]->getGreen() == 0);
//                 REQUIRE(testDisplay[i][j]->getBlue() == 0);
//             }
//         }

//         activeDisplay = create5By5LEDGrid(true);
//         testGrid = new LEDGrid(5, 5);
//         testGrid->updateDisplay(5, 5, activeDisplay);
//         testDisplay = testGrid->getDisplay();

//         for(int i = 0; i < 5; i ++) {
//             for(int j = 0; j < 5; j++) {
//                 REQUIRE(testDisplay[i][j]->getRed() == 0);
//                 REQUIRE(testDisplay[i][j]->getGreen() == 0);
//                 REQUIRE(testDisplay[i][j]->getBlue() == 0);
//             }
//         }
//     }
// }

// TEST_CASE("Invalid LEDGrid test cases") {
//     LEDGrid *testGrid;
//     LED ***testDisplay;

//     SECTION("Testing changing entire display when sizes do not match") {
//         LED ***activeDisplay = create5By5LEDGrid(false);
//         testGrid = new LEDGrid(2, 2);
//         testGrid->updateDisplay(5, 5, activeDisplay);
//         testDisplay = testGrid->getDisplay();

//         for(int i = 0; i < 2; i ++) {
//             for(int j = 0; j < 2; j++) {
//                 REQUIRE(testDisplay[i][j]->getRed() == 0);
//                 REQUIRE(testDisplay[i][j]->getGreen() == 0);
//                 REQUIRE(testDisplay[i][j]->getBlue() == 0);
//             }
//         }

//         testGrid = new LEDGrid(8, 8);
//         testGrid->updateDisplay(5, 5, activeDisplay);
//         testDisplay = testGrid->getDisplay();

//         for(int i = 0; i < 5; i ++) {
//             for(int j = 0; j < 5; j++) {
//                 REQUIRE(testDisplay[i][j]->getRed() == 0);
//                 REQUIRE(testDisplay[i][j]->getGreen() == 0);
//                 REQUIRE(testDisplay[i][j]->getBlue() == 0);
//             }
//         }
//     }
// }

// LED ***create5By5LEDGrid(bool nullGrid) {
//     LED ***newDisplay = new LED**[5];

//     for(int i = 0; i < 5; i++) {
//         newDisplay[i] = new LED*[5];
//     }

//     for(int i = 0; i < 5; i++) {
//         for(int j = 0; j < 5; j++) {
//             if(nullGrid) {
//                 newDisplay[i][j] = nullptr;
//             }
//             else {
//                 newDisplay[i][j] = new LED();
//                 newDisplay[i][j]->setRGB(170, 152, 169);
//             }
//         }
//     }

//     return newDisplay;
// }