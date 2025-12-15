#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include "CommonFunctions.h"

using namespace std;

void program3() {
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";

    cout << "Введите строку: ";

    int capacity = 2;
    char* str = (char*)malloc(capacity * sizeof(char));
    str[0] = '\0';
    int length = 0;

    char ch;
    while ((ch = cin.get()) != '\n') {
        if (length + 1 >= capacity) {
            capacity++;
            char* newStr = (char*)malloc(capacity * sizeof(char));
            strcpy(newStr, str);
            free(str);
            str = newStr;
        }
        str[length++] = ch;
        str[length] = '\0';
    }

    ofstream outFile(inputFile);
    outFile << str;
    outFile.close();
    free(str);

    capacity = 2;
    char* fileStr = (char*)malloc(capacity * sizeof(char));
    fileStr[0] = '\0';
    length = 0;

    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "Ошибка открытия файла!" << endl;
        free(fileStr);
        return;
    }

    while (inFile.get(ch) && ch != '\n') {
        if (length + 1 >= capacity) {
            capacity++;
            char* newStr = (char*)malloc(capacity * sizeof(char));
            strcpy(newStr, fileStr);
            free(fileStr);
            fileStr = newStr;
        }
        fileStr[length++] = ch;
        fileStr[length] = '\0';
    }
    inFile.close();

    fileStr = processStringDynamic(fileStr, capacity);

    ofstream resultFile(outputFile);
    resultFile << fileStr;
    resultFile.close();

    cout << "Результат: " << fileStr << endl;
    cout << "Записан в файл: " << outputFile << endl;

    free(fileStr);
}