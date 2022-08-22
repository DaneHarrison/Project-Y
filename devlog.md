# Dev Activity: 
August 6:  
Dane (2 hrs)  
- researched safety risks
- planned rough code structure
- researched 3D printing joint techniques

August 17:
Dane (6 hrs)
- Generated rough file structure considering SOLID principles and design patterns
- Learnt how to reference files in other directories in C++ (uses relative pathing)
- Learnt how to use CMake
- Researched testing in C++ 
- setup catch2 (thanks Josef for telling me about it!)
- updated docs
- got tests and project executables functional!

August 19:
Dane (7 hrs)
- Finished setting up common interfaces
- Furthered my understanding of cmake and cleaned up my cmake files
- Setup testing for LED
- Adjusted LED Display interface (added more pointers and a deconstructor)
- Started TDD with LEDGrid
- Learnt dynamically calculating array length is not easy in C++ - cannot use sizeof (since LED is not primitive) maybe this can be changed to use templates in the future (if this approach is taken lengths must be known at compile time)
- Wrote a few tests and some of the more basic LEDGrid functionality
- Learnt functions that are not declared in the header file (only .cpp) cannot access class parts i.e private variables

August 21:
Dane (3 hrs)
- Created a static lilac pattern
- Fleshed out the arduino device class - added arduino dependent code
- Created a minimal version of VisualizerLogic (future versions will randomize patterns and track them as well)
- Started relearning how to use CAD software
- Added some documentation
- Learnt that adding comments directly above a class/function/variable will provide a brief description in vs code (forward referencing messes with classes though)

August 22:
Dane (2 hrs)
- Improved documentation
- Adding documentation helps detect duplicate code!

<br>
<br>

//TODO:

    System:
    - Figure out how to make cmake and arduino compilations compatible
    - optimize cmake file (currently we do not use private which might be needed for easier testing - double check)
     
    LEDDisplay:
    - Move LED*** from child classes to parent
    - remove duplicate code in strip and grid by moving instances to abstract LEDDisplay (turnOff, getDisplay, probably more!)

    LED:
    - LED copy constructor

    VisualizerLogic:
    - add the ability to add multiple patterns (can use arrays qith modulo, dependency injection, constants etc...)
    - add pattern range times (random between min and max)
    - add random pattern selection/pattern management logic