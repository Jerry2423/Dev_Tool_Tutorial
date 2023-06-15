### Sanitizer

### Compile Options Setting

`target_compile_options(main PRIVATE -fsanitize=address -Wall -Werror -Wextra)`
related [readings](https://www.foonathan.net/2018/10/cmake-warnings/)

In the `target_compile_options`, `Wall`: warning all; `Werror`: treat all warnings as errors; `Wextra`: warning extra stuff

`target_link_options(main PRIVATE -fsanitize=address)`

**Sanitizer Setting**: `-fsanitize={NAME}`:
In Apple Clang, there are 3 kinds of sanitizer: address(memory detect included); undefined; thread.
For more information, check the [document](https://developer.apple.com/documentation/xcode/diagnosing-memory-thread-and-crash-issues-early)

[switching between compilers](https://stackoverflow.com/questions/7031126/switching-between-gcc-and-clang-llvm-using-cmake)

