### Sanitizer

### Compile Options Setting

`target_compile_options(main PRIVATE -fsanitize=address -Wall -Werror -Wextra)`

In the `target_compile_options`, `Wall`: warning all; `Werror`: treat all warnings as errors; `Wextra`: warning extra stuff

`target_link_options(main PRIVATE -fsanitize=address)`

**Sanitizer Setting**: `-fsanitize={NAME}`:
In Apple Clang, there are 3 kinds of sanitizer: address(memory detect included); undefined; thread.
For more information, check the [document](https://developer.apple.com/documentation/xcode/diagnosing-memory-thread-and-crash-issues-early)
