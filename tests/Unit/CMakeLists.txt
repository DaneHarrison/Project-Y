set(LIBRARY_NAME unitTests)
set(HEADER_FILES catch.hpp)

set(SOURCE_FILES 
    testLED.cpp
)

add_executable(unitTests ${SOURCE_FILES})