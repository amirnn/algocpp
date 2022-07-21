cmake_minimum_required(VERSION 3.20.0)
project(algocpp VERSION 0.1.0)

include(CTest)
enable_testing()

include(${CMAKE_SOURCE_DIR}/conan/dep/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory("src")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
