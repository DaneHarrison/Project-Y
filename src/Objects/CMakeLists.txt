add_library(FTTReader FTTReader.cpp)
add_library(LED LED.cpp)
add_library(LEDDisplay LEDDisplay.cpp)
add_library(LEDGrid LEDGrid.cpp)
add_library(LEDStrip LEDStrip.cpp)
add_library(SolidPattern SolidPattern.cpp)

target_link_libraries(LEDStrip LED)
target_link_libraries(LEDGrid LED)

target_link_libraries(LEDStrip LEDDisplay)
target_link_libraries(LEDGrid LEDDisplay)

target_link_libraries(LEDGrid LEDStrip)

target_link_libraries(LEDStrip SolidPattern)
target_link_libraries(LEDGrid SolidPattern)