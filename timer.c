//
// Created by JDubo on 25.12.2024.
//

#include "timer.h"
#include <time.h>


double measureTime(void (*sortFunc)(int*, int), int* arr, int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunc(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}
