#define CATCH_CONFIG_MAIN
#include "catch.hpp"


// A function to test
int add(int a, int b) {
    return a + b;
}

// Test cases
TEST_CASE("Addition works", "[math]") {
    REQUIRE(add(1, 1) == 2);
    REQUIRE(add(2, 2) == 4);
}

TEST_CASE("Addition with negative numbers", "[math]") {
    REQUIRE(add(-1, 1) == 0);
    REQUIRE(add(-2, -2) == -4);
}