## Crash on Cmake

Idea:
> Cmake makes the makefiles for you automatically.

### Basic Mode


Create a file with the **exact same name** `CMakeLists.txt`                                                     

Then type the following code:

```
cmake_minimum_required(VERSION {number of cmake_version})

project({project_name})

add_executable(${PROJECT_NAME} {source_file_name}) //normally for main.cpp etc to generate a executable file.
```

Create a building directory and enter in it:
`mkdir build`
`cd build`

Run the cmake command:
`cmake [options] -S <path-to-source> -B <path-to-build>`
For convenience, if the source file `main.cpp` is in the parent directory and we are in the building directory, then there is no need to write things after and included`-B`:
`cmake -S ..`

The Makefile and executable file is made in the building directory


### Working with Libraries

Idea: Use Cmake generate `.a` library file then link the lib file in the main program

**For Lib Files**

In the `CMakeLists.txt`
```
cmake_minimum_required(VERSION {version})
project({lib_name})
add_library(lib_name {lib_header}.h {lib_def}.cpp)
```

Create building directory and 
`cmake [options] -S <path-to-source> -B <path-to-build>`

In the building directory we can see a file `lib{class_name}.a`, which is what we want.

**For Main Files**

In the `CMakeLists.txt`
```
cmake_minimum_required(VERSION {version})
project(name)
add_executable({executable_name} {source_file_name})
target_link_directories({executable_name_defined_before} {PRIVATE/PUBLIC} {directory_where_the_lib{class_name}.a_lies})
target_link_libraries({executable_name_defined_before} {class_name})

```

Create building directory and 
`cmake [options] -S <path-to-source> -B <path-to-build>`

However, in the `main.cpp`, we need to add the path where the `.h` files lies in the `#include ""`:
`#include "{path}/{class_name}.h"`

### Extra

When new files are added, change the `CMakeLists.txt` at the root directory.

Add new libraries:
`target_link_libraries`
`target_include_directories`
