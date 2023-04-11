# event-handler
Simple event handling library in C.

## How it works?
TBD

## How to compile and link it?

Just include this directory in your CMake project. Remember to specify the event handler buffer size.

Example `CMakeLists.txt` content:
```
...

add_subdirectory(<PATH TO EVENT HANDLER LIBRARY>)

target_compile_definitions(event_handler PRIVATE EVENT_HANDLERS_MAX_HANDLERS_COUNT=100)
target_link_libraries(${PROJECT_NAME} PRIVATE event_handler)

...
```

# Copyright
This library was written by Grzegorz Grzęda, and is distributed under MIT Licence. Check the `LICENSE` file for
more details.