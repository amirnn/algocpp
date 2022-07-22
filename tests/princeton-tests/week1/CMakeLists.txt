# Week 1

# add_hw_test(testhw1 hw1 test1.cpp)

# Make test executable
add_executable(test1 test1.cc)
target_link_libraries(test1  ${CONAN_LIBS})

doctest_discover_tests(test1)