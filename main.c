#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"
#include "sorting.h"
#include "io.h"
#include "timer.h"

int main(int argc, char* argv[]) {
    char filename[256] = "output.txt";
    int* prev_arr = NULL;
    int prev_arr_size = 0;

    if(argc > 1 && strcmp(argv[1], "--file") == 0 && argc > 2) {
        strcpy(filename, argv[2]);
        if (readArrayFromFile(filename, &prev_arr, &prev_arr_size) == 0) {
            printf("Previous array: ");
            for (int i = 0; i < prev_arr_size; i++) {
                printf("%d ", prev_arr[i]);
            }
            printf("\n");
            int* sorted_prev_arr = (int*) malloc(sizeof(int) * prev_arr_size);
            if (sorted_prev_arr == NULL) return 1;
            memcpy(sorted_prev_arr, prev_arr, sizeof(int) * prev_arr_size);
            bubbleSort(sorted_prev_arr, prev_arr_size);

            printf("Sorted previous array: ");
            for (int i = 0; i < prev_arr_size; i++) {
                printf("%d ", sorted_prev_arr[i]);
            }
            printf("\n");
            free(sorted_prev_arr);
            free(prev_arr);
        } else {
            printf("File not found or error");
        }
    }
    Deque* deque = createDeque();
    int num;
    printf("Enter numbers separated by spaces: ");
    while (scanf("%d", &num) == 1) {
        pushRear(deque, num);
        if(getchar() == '\n') break;
    }

    int deque_size = dequeSize(deque);
    int* array = dequeToArray(deque);
    if(array == NULL) return 1;
    writeArrayToFile(filename, array, deque_size);
    int* arr_copy_bubble = (int*) malloc(sizeof(int) * deque_size);
    if (arr_copy_bubble == NULL) return 1;
    memcpy(arr_copy_bubble, array, sizeof(int) * deque_size);
    bubbleSort(arr_copy_bubble, deque_size);
    writeArrayToFile("sorted_output.txt", arr_copy_bubble, deque_size);
    int* arr_copy_heap = (int*) malloc(sizeof(int) * deque_size);
    if (arr_copy_heap == NULL) return 1;
    memcpy(arr_copy_heap, array, sizeof(int) * deque_size);

    double time_bubble = measureTime(bubbleSort, arr_copy_bubble, deque_size);
    double time_heap = measureTime(heapSort, arr_copy_heap, deque_size);
    printf("Bubble Sort time: %f seconds\n", time_bubble);
    printf("Heap Sort time: %f seconds\n", time_heap);

    freeDeque(deque);
    free(array);
    free(arr_copy_bubble);
    free(arr_copy_heap);

    return 0;
}
