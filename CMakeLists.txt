# TOP
cmake_minimum_required(VERSION 3.26.4)
project(algocpp VERSION 0.1.0 LANGUAGES C CXX)

# For C++ 23 Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# For clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
add_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else()
  add_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()



include("conan/dependencies.cmake")

add_subdirectory("src")




# include(CTest)
# enable_testing()
# add_subdirectory("tests")

