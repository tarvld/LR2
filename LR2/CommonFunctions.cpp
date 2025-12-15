#define _CRT_SECURE_NO_WARNINGS
#include "CommonFunctions.h"
#include <cstring>
#include <iostream>
#include <cctype>

using namespace std;

// Проверка английской согласной
bool isConsonant(char c) {
    // Английские согласные буквы
    const char* consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    return strchr(consonants, c) != nullptr;
}

// Обработка строки для динамической памяти
char* processStringDynamic(char* str, int& capacity) {
    int len = strlen(str);
    char* result = str;

    if (len > 0 && str[0] == 'a') {
        // Проверяем, нужно ли увеличивать capacity
        if (len + 2 > capacity) {
            // Вместо realloc, просто вернем ошибку или не делаем изменения
            // Так как предполагается, что capacity уже достаточно
            cerr << "Error: not enough capacity!" << endl;
            return str;
        }

        // Сдвигаем символы вправо
        for (int j = len; j >= 0; j--) {
            str[j + 1] = str[j];
        }
        str[1] = 'a';
        len++;
    }

    // ... остальной код без изменений
    return result;
}

// Статическая версия обработки строки
void processString(char* str) {
    int dummyCapacity = 1000;
    processStringDynamic(str, dummyCapacity);
}
