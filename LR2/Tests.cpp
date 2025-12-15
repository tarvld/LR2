#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CommonFunctions.h"
#include <Windows.h>
#include <locale>

struct ConsoleSetup {
    ConsoleSetup() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        setlocale(LC_ALL, "Russian");
    }
};

//Начальная а заменяется на аа

TEST_CASE("program1.2", "[unit]") {
    char str[100] = "абв";
    program1(str);
    REQUIRE(strcmp(str, "аАбв") == 0);
}

// а перед согласной заменяется на А

TEST_CASE("program1.3", "[unit]") {
    char str[100] = "мабв";
    program1(str);
    REQUIRE(strcmp(str, "мАбв") == 0);
}

// а в конце не меняется

TEST_CASE("program1.4", "[unit]") {
    char str[100] = "абва";
    program1(str);
    REQUIRE(strcmp(str, "аАбва") == 0);
}

//а перед гласной не заменяется на А

TEST_CASE("program1.5", "[unit]") {
    char str[100] = "нонао";
    program1(str);
    REQUIRE(strcmp(str, "нонао") == 0);
}