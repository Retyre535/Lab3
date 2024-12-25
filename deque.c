#include <stdlib.h>
#include <stdio.h>
#include "deque.h"

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) return NULL;
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

void pushFront(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;
    if (deque->front == NULL) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
}

void pushRear(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;
    if (deque->rear == NULL) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
}

int popFront(Deque* deque) {
    if (deque == NULL || deque->front == NULL) return -1;
    int data = deque->front->data;
    Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
    return data;
}

int popRear(Deque* deque) {
    if (deque == NULL || deque->rear == NULL) return -1;
    int data = deque->rear->data;
    Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if(deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
    return data;
}

void freeDeque(Deque* deque) {
    while (deque->front != NULL) {
        popFront(deque);
    }
    free(deque);
}

int dequeSize(Deque* deque) {
    if (deque == NULL) return 0;
    int count = 0;
    Node* current = deque->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void printDeque(Deque* deque) {
    if (deque == NULL) return;
    Node* current = deque->front;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int* dequeToArray(Deque* deque) {
    if (deque == NULL || deque->front == NULL) return NULL;
    int size = dequeSize(deque);
    int* array = (int*)malloc(sizeof(int) * size);
    if(array == NULL) return NULL;
    Node* current = deque->front;
    for (int i = 0; i < size; i++) {
        array[i] = current->data;
        current = current->next;
    }
    return array;
}
