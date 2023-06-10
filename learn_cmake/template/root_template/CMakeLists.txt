#Basic
cmake_minimum_required(VERSION 3.16)

project(NAME)

add_executable([Target Name] [Dependency File]])

set(CMAKE_CXX_STANDARD_REQUIRED 17)

# Add Libraries (at the root of the project)
add_subdirectory(${CMAKE_SOURCE_DIR}/...) #Go to the lib's directories and check their cmake lists


# Note: for all target function, remember to add target name first
# A target is an executable file created by add_executable() / add_library()...

#If the code needs to use other functions from other libraries, we need to link to the library so that we can find the definition(not declaration) for the function
target_link_libraries([target] [lib name])

#If the code needs to add #include, the need to know where the .hpp/.h(interface) is
target_include_directories([target] [PUBLIC/PRIVATE] [DIRECTORIES]) # note the public and private means whether this include is public to all the code


