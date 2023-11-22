# template-math
A template based mathematical library in C++ that supports basic arithmetic operations at compile time.
This was built for learning & practicing template metaprogramming in C++.

All of the code can be found under `include/template_math.h`.

You can build the library with CMake relatively easily with the following commands:
  - `cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=RELEASE|DEBUG -DTM_BUILD_TESTS=ON|OFF`
  - `cd build`
  - `cmake --build .`

The option `TM_BUILD_TESTS` will conditionally build a test executable or not.
