add_library(FTTReader FTTReader.cpp)
add_library(LED LED.cpp)
add_library(LEDGrid LEDGrid.cpp)
add_library(LEDStrip LEDStrip.cpp)

target_link_libraries(LEDStrip LED)
target_link_libraries(LEDGrid LED)