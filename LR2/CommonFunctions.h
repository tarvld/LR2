#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

#include <cstring>

bool isConsonant(char c);
void processString(char* str);
char* processStringDynamic(char* str, int& capacity);
void program1(char* str);
char* program2(const char* input);  
void program3(const char* input, const char* inputFile = "input.txt", const char* outputFile = "output.txt");

#endif