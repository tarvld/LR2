#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#include "CommonFunctions.h"

using namespace std;

// Функция для проверки согласной
//static bool isConsonant(char c) {
//    const char* consonants = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
//    return strchr(consonants, c) != nullptr;
//}
//
//// Функция обработки строки
//static char* processStringDynamic(char* str, int& capacity) {
//    int len = strlen(str);
//
//    if (len > 0 && str[0] == 'а') {
//        if (len + 2 > capacity) {
//            int newCapacity = len + 2;
//            char* newStr = (char*)malloc(newCapacity * sizeof(char));
//
//            if (!newStr) {
//                return str;
//            }
//
//            newStr[0] = 'а';
//            newStr[1] = 'а';
//            // Заменено strcpy на strcpy_s
//            strcpy_s(newStr + 2, newCapacity - 2, str + 1);
//
//            free(str);
//            str = newStr;
//            capacity = newCapacity;
//            len = strlen(str);
//        }
//        else {
//            for (int j = len; j >= 0; j--) {
//                str[j + 1] = str[j];
//            }
//            str[1] = 'а';
//            len++;
//        }
//    }
//
//    for (int i = 1; i < len; i++) {
//        if (str[i] == 'а' && str[i + 1] != '\0' && isConsonant(str[i + 1])) {
//            str[i] = 'А';
//        }
//    }
//
//    return str;
//}

// Основная функция program1 - принимает строку для обработки
void program1(char* inputStr) {
    if (inputStr == nullptr) {
        cout << "Ошибка: передан null указатель!" << endl;
        return;
    }

    int len = strlen(inputStr);
    int capacity = len + 10;

    char* str = (char*)malloc(capacity * sizeof(char));
    if (!str) {
        cout << "Ошибка выделения памяти!" << endl;
        return;
    }

    // Заменено strcpy на strcpy_s
    strcpy_s(str, capacity, inputStr);

    str = processStringDynamic(str, capacity);

    cout << "Результат: " << str << endl;

    // Заменено strcpy на strcpy_s
    strcpy_s(inputStr, len + 10, str);

    free(str);
}