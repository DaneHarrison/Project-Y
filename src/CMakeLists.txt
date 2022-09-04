cmake_minimum_required(VERSION 3.20.0)
project(Project-Y)

# Creates an executable
add_executable(${PROJECT_NAME} main.cpp)

# Adds and starts preparing CMakeFiles in other directories
add_subdirectory(Interfaces)
add_subdirectory(Arduino)
add_subdirectory(Objects)
add_subdirectory(Logic)
add_subdirectory(../tests/unit ../tests/unit)

# Adds directories to link other object files from
target_link_directories(${PROJECT_NAME} INTERFACE Interfaces)
target_link_directories(${PROJECT_NAME} PUBLIC Arduino)
target_link_directories(${PROJECT_NAME} PUBLIC Logic)
target_link_directories(${PROJECT_NAME} PUBLIC Objects)

# Links all the classes to main
target_link_libraries(${PROJECT_NAME} VisualizerLogic)
target_link_libraries(${PROJECT_NAME} Arduino)
target_link_libraries(${PROJECT_NAME} FTTReader)
target_link_libraries(${PROJECT_NAME} LED)
target_link_libraries(${PROJECT_NAME} LEDDisplay)
target_link_libraries(${PROJECT_NAME} LEDGrid)
target_link_libraries(${PROJECT_NAME} LEDStrip)