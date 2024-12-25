//
// Created by JDubo on 25.12.2024.
//

#ifndef UNTITLED_IO_H
#define UNTITLED_IO_H

#include <stdlib.h>
#include <stdio.h>

int writeArrayToFile(const char* filename, int* arr, int n);
int readArrayFromFile(const char* filename, int** arr, int* n);

#endif //UNTITLED_IO_H
