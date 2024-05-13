#pragma once
#include <stdexcept>
#define MAX_SIZE 20

template<typename T>
class Stack{
    T arr[MAX_SIZE];
    int size;
public:
    Stack() : size{ 0 } {}

    Stack(T data) : size{ 1 } { arr[0] = data; }

    void push(T data) {
        if (size == SIZE_MAX) throw std::overflow_error("Переповнення стека!");
        arr[size] = data;
        size++;
    }

    T pop() {
        if (size == 0) throw std::out_of_range("Стек порожній!");
        size--;
        return arr[size];
    }

    T peek() { return arr[size - 1]; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == MAX_SIZE; }
};

