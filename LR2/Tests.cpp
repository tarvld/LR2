#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CommonFunctions.h"

TEST_CASE("program1.1") {
    char str[100] = "abc";
    program1(str);
    REQUIRE(strcmp(str, "aabc") == 0);
}

TEST_CASE("program1.2") {
    char str[100] = "macb";
    program1(str);
    REQUIRE(strcmp(str, "macb") == 0);
}

TEST_CASE("program1.3") {
    char str[100] = "abca";
    program1(str);
    REQUIRE(strcmp(str, "aabca") == 0);
}

TEST_CASE("program1.4") {
    char str[100] = "nonae";
    program1(str);
    REQUIRE(strcmp(str, "nonae") == 0);
}

TEST_CASE("program1.5") {
    char str[100] = "test";
    program1(str);
    REQUIRE(strcmp(str, "test") == 0);
}
//

TEST_CASE("program2.1") {
    char* result = program2("abc");
    REQUIRE(strcmp(result, "aAbc") == 0);
    free(result);
}

TEST_CASE("program2.2 ") {
    char* result = program2("macb");
    REQUIRE(strcmp(result, "mAcb") == 0);
    free(result);
}

TEST_CASE("program2.3") {
    char* result = program2("abca");
    REQUIRE(strcmp(result, "aAbca") == 0);
    free(result);
}

TEST_CASE("program2.4") {
    char* result = program2("nonae");
    REQUIRE(strcmp(result, "nonae") == 0);
    free(result);
}

TEST_CASE("program2.5") {
    char* result = program2("test");
    REQUIRE(strcmp(result, "test") == 0);
    free(result);
}