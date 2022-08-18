add_library(Arduino Arduino.cpp)
add_subdirectory(../Logic ../Logic)
target_link_directories(Arduino PUBLIC Logic)


target_link_libraries(Arduino VisualizerLogic) #needs to be built by this one

#target_include_directories()   