#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "CommonFunctions.h"

using namespace std;

void program1(char* inputStr) {
    if (inputStr == nullptr) {
        cout << "Error: null pointer!" << endl;
        return;
    }

    int capacity = strlen(inputStr) + 10;
    char* str = (char*)malloc(capacity * sizeof(char));

    if (!str) {
        cout << "Memory allocation error!" << endl;
        return;
    }

    strcpy(str, inputStr);
    processString(str);

    //cout << "Result: " << str << endl;
    strcpy(inputStr, str);

    free(str);
}