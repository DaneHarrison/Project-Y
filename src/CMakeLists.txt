cmake_minimum_required(VERSION 3.20.0)
project(Project-Y)

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(Arduino)
add_subdirectory(Objects)
add_subdirectory(../tests/Unit ../tests/unit)

target_link_directories(${PROJECT_NAME} PUBLIC Arduino)
target_link_directories(${PROJECT_NAME} PUBLIC Objects)

target_link_libraries(${PROJECT_NAME} Arduino)
target_link_libraries(${PROJECT_NAME} MicInput)

target_link_libraries(${PROJECT_NAME} FTTReader)
target_link_libraries(${PROJECT_NAME} LED)
target_link_libraries(${PROJECT_NAME} MicInput)
target_link_libraries(${PROJECT_NAME} LEDGrid)
target_link_libraries(${PROJECT_NAME} LEDStrip)