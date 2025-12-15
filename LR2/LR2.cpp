#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "CommonFunctions.h"

using namespace std;

void clear_screen() {
    system("cls");
}

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do {
        clear_screen();

        cout << "=========================================" << endl;
        cout << "     ЛАБОРАТОРНАЯ РАБОТА №2" << endl;
        cout << "  Динамическое распределение памяти" << endl;
        cout << "=========================================" << endl;
        cout << "1. Программа 1 (malloc/free)" << endl;
        cout << "2. Программа 2 (calloc/realloc)" << endl;
        cout << "3. Программа 3 (работа с файлами)" << endl;
        cout << "0. Выход" << endl;
        cout << "=========================================" << endl;
        cout << "Выберите программу: ";
        cin >> choice;
        cin.ignore();

        clear_screen();

        switch (choice) {
        case 1: {
            cout << "=== Запуск программы 1 ===" << endl;
            cout << "Введите строку: ";
            char input[256];
            cin.getline(input, 256);
            program1(input);
            break;
        }
        case 2:
            cout << "=== Запуск программы 2 ===" << endl;
            program2();
            break;
        case 3:
            cout << "=== Запуск программы 3 ===" << endl;
            program3();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
        }

        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.get();
        }

    } while (choice != 0);

    return 0;
}