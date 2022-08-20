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


<br>
<br>

TODO: