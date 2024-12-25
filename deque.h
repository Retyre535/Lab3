//
// Created by JDubo on 25.12.2024.
//

#ifndef UNTITLED_DEQUE_H
#define UNTITLED_DEQUE_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

Deque* createDeque();
void pushFront(Deque* deque, int data);
void pushRear(Deque* deque, int data);
int popFront(Deque* deque);
int popRear(Deque* deque);
void freeDeque(Deque* deque);
int dequeSize(Deque* deque);
void printDeque(Deque* deque);
int* dequeToArray(Deque* deque);

#endif //UNTITLED_DEQUE_H
