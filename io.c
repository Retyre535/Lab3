//
// Created by JDubo on 25.12.2024.
//


#include <stdlib.h>
#include <stdio.h>
#include "io.h"

int writeArrayToFile(const char* filename, int* arr, int n) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return -1;
    }
    for(int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fprintf(file, "\n");
    fclose(file);
    return 0;
}

int readArrayFromFile(const char* filename, int** arr, int* n) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return -1;
    }

    int capacity = 10;
    *arr = (int*) malloc(sizeof(int) * capacity);
    if (*arr == NULL) return -1;
    *n = 0;
    int number;
    while (fscanf(file, "%d", &number) == 1) {
        if(*n >= capacity) {
            capacity *= 2;
            int* temp = realloc(*arr, sizeof(int) * capacity);
            if (temp == NULL) {
                free(*arr);
                fclose(file);
                return -1;
            }
            *arr = temp;
        }
        (*arr)[(*n)++] = number;
    }
    fclose(file);
    return 0;
}


