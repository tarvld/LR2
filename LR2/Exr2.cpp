#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <Windows.h>

using namespace std;

static bool isConsonant(char c) {
    const char* consonants = "áâãäæçéêëìíïðñòôõö÷øùÁÂÃÄÆÇÉÊËÌÍÏÐÑÒÔÕÖ×ØÙ";
    return strchr(consonants, c) != nullptr;
}

static void processString(char* str) {
    int len = strlen(str);

    if (len > 0 && str[0] == 'à') {
        for (int j = len; j >= 0; j--) {
            str[j + 1] = str[j];
        }
        str[1] = 'à';
        len = strlen(str);
    }

    for (int i = 1; i < len; i++) {
        if (str[i] == 'à' && str[i + 1] != '\0' && isConsonant(str[i + 1])) {
            str[i] = 'À';
        }
    }
}

void program2() {
    cout << "Ââåäèòå ñòðîêó: ";

    const int CHUNK_SIZE = 5;
    int capacity = CHUNK_SIZE;
    int length = 0;

    char* str = (char*)calloc(capacity, sizeof(char));

    char ch;
    while ((ch = cin.get()) != '\n') {
        if (length + 1 >= capacity) {
            capacity += CHUNK_SIZE;
            char* temp = (char*)realloc(str, capacity * sizeof(char));
            str = temp;

            for (int i = length; i < capacity; i++) {
                str[i] = '\0';
            }
        }

        str[length++] = ch;
        str[length] = '\0';
    }

    processString(str);

    cout << "Ðåçóëüòàò: " << str << endl;

    free(str);
}