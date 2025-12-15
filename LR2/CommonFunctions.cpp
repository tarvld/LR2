#define _CRT_SECURE_NO_WARNINGS
#include "CommonFunctions.h"
#include <cstring>
#include <iostream>

using namespace std;

bool isConsonant(char c) {
    const char* consonants = "áâãäæçéêëìíïðñòôõö÷øùÁÂÃÄÆÇÉÊËÌÍÏÐÑÒÔÕÖ×ØÙ";
    return strchr(consonants, c) != nullptr;
}

char* processStringDynamic(char* str, int& capacity) {
    int len = strlen(str);
    char* result = str;

    if (len > 0 && str[0] == 'à') {
        if (len + 2 > capacity) {
            capacity = len + 2;
            char* newStr = (char*)realloc(str, capacity * sizeof(char));

            if (!newStr) {
                cerr << "Îøèáêà ïåðåðàñïðåäåëåíèÿ ïàìÿòè!" << endl;
                return str;
            }

            result = newStr;
            str = newStr;
        }

        for (int j = len; j >= 0; j--) {
            str[j + 1] = str[j];
        }
        str[1] = 'à';
        len++;
    }

    for (int i = 1; i < len; i++) {
        if (str[i] == 'à' && str[i + 1] != '\0' && isConsonant(str[i + 1])) {
            str[i] = 'À';
        }
    }

    return result;
}

void processString(char* str) {
    int dummyCapacity = 1000;
    processStringDynamic(str, dummyCapacity);
}