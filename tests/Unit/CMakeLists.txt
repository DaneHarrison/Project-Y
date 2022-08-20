# Creates the library name
set(LIBRARY_NAME unitTests)

# Put all unit test files in here
set(SOURCE_FILES 
    testLED.cpp
    testLEDStrip.cpp
    testLEDGrid.cpp
    testFTTReader.cpp
)

add_executable(${LIBRARY_NAME} ${SOURCE_FILES})

target_link_libraries(${LIBRARY_NAME} LED)
target_link_libraries(${LIBRARY_NAME} LEDStrip)
target_link_libraries(${LIBRARY_NAME} LEDGrid)
target_link_libraries(${LIBRARY_NAME} FTTReader)