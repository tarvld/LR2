#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "CommonFunctions.h"

using namespace std;

char* program2(const char* input) {

    if (input == nullptr) {
        return nullptr;
    }

    int len = strlen(input);
    char* str = (char*)malloc((len + 10) * sizeof(char));

    if (!str) {
        return nullptr;
    }

    strcpy(str, input);

    if (len > 0 && str[0] == 'a') {
        for (int j = len; j >= 0; j--) {
            str[j + 1] = str[j];
        }
        str[1] = 'a';
        len = strlen(str);  
    }

    for (int i = 1; i < len; i++) {
        if (str[i] == 'a' && str[i + 1] != '\0') {

            if (isConsonant(str[i + 1])) {
                str[i] = 'A';
            }
        }
    }

    return str;
}