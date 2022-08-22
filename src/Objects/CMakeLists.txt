add_library(FTTReader FTTReader.cpp)
add_library(LED LED.cpp)
add_library(LEDGrid LEDGrid.cpp)
add_library(LEDStrip LEDStrip.cpp)
add_library(FillLilacPattern FillLilacPattern.cpp)

target_link_libraries(LEDStrip LED)
target_link_libraries(LEDGrid LED)

target_link_libraries(LEDStrip FillLilacPattern)
target_link_libraries(LEDGrid FillLilacPattern)