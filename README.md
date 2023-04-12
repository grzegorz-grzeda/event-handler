# event-handler
Simple event handling library in C.

## How it works?
1. Register your `event_handler_t` callback funcion, through `register_event_handler()`. Specify the event ID and
maybe some context, which will be passed to the callback.
1. Place in code the `send_event_to_handlers()` call. Specify the event ID and maybe pass some additional payload.
All registered to this event callbacks will be invoked in the context of the caller.
1. This is a small and simple library, so you have to ensure, that callbacks can access external resources in a safe
manner. When calling `send_event_to_handlers()` from an ISR or other thread, the callback has to have e.g. a queue, 
mutex, semaphore, etc. mechanism to cross the thread barrier safely.

## Run tests
Just run `./test.sh`.

## How to compile and link it?

Just include this directory in your CMake project. Remember to specify the event handler buffer size.

Example `CMakeLists.txt` content:
```
...

add_subdirectory(<PATH TO EVENT HANDLER LIBRARY>)

target_compile_definitions(event_handler PRIVATE EVENT_HANDLERS_MAX_HANDLERS_COUNT=20)
target_link_libraries(${PROJECT_NAME} PRIVATE event_handler)

...
```

## Documentation
If you want, you can run `doxygen` to generate HTML documentation. It will be available in `documentation` 
directory.


# Copyright
This library was written by Grzegorz Grzęda, and is distributed under MIT Licence. Check the `LICENSE` file for
more details.