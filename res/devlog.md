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

August 24:  
Dane (8 hrs)
- Learnt how to navigate through blender and apply basic operations
- Learnt how to utilize scripts to automate otherwise tedious tasks
- Learnt that collection indexs do not match up with order (names are more consistant)
- Learnt about materials and animation
- Learnt the importance of setting to scale
- Learnt arrays suck - does not allow for individual modification (you can seperate them with p in edit mode but this kept causing blender to crash)
- Created base shirt model
- Created LEDs

August 25:  
Dane (3 hrs)
- Wrote the blender animation script
- Created readme gif

August 30:  
Dane (5 hrs)
- Researched arduino information:
    - Learnt pin 0 has the best performance in terms of audio processing
    - Learnt can use less ram by changing all ints to short ints
- Relearnt onshape
- Started designing LED strip connectors

September 1:  
Dane (4 hrs)
- Researched materials needed to finish the project
- Researched power solutions
- Documented research and build plans into res/details.md
- Created a basic diagram

<br>
<br>

//TODO:

    System:
    - Figure out how to make cmake and arduino compilations compatible
    - optimize cmake file (currently we do not use private which might be needed for easier testing - double check)
    - change all instances of int to short int
     
    LEDDisplay:
    - Move LED*** from child classes to parent
    - remove duplicate code in strip and grid by moving instances to abstract LEDDisplay (turnOff, getDisplay, probably more!)

    LED:
    - LED copy constructor

    VisualizerLogic:
    - add the ability to add multiple patterns (can use arrays qith modulo, dependency injection, constants etc...)
    - add pattern range times (random between min and max)
    - add random pattern selection/pattern management logic