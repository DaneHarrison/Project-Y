add_library(Arduino Arduino.cpp)

target_link_libraries(Arduino LEDStrip)
target_link_libraries(Arduino LEDGrid)