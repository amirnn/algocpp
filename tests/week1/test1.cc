#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"

#include "io.hpp"

int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function") {

    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}

TEST_CASE("Test the file process function") {

    String file_path{"/Users/amirnourinia/Developer/algocpp/tests/week1/client.txt"};
    auto result = read_file(file_path);
    if (result.has_value()) {
        File file = result.value();
        String file_txt = file.content();
        auto lines = file.get_lines();

        CHECK(lines.at(0) == "10");
        CHECK(lines.at(1) == "4 3");

    } else {
        print("Empty value in optional.");
        FAIL("Test Failed!");
    }
}

TEST_CASE("Test processing of the number of nodes.") {

    String file_path{"/Users/amirnourinia/Developer/algocpp/tests/week1/client.txt"};
    auto result = read_file(file_path);
    if (result.has_value()) {
        File file = result.value();
        String file_txt = file.content();
        auto lines = file.get_lines();
        CHECK(file.get_node_count() == 10);
    } else {
        print("Empty value in optional.");
        FAIL("Test Failed!");
    }

}