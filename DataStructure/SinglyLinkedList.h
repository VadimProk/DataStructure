#pragma once
#include <ostream>
#include "../DataStructure/SingleNode.h"

using namespace std;
template <typename T>
class SinglyLinkedList{
private:
	std::unique_ptr<single_node::Node<T>> head;
	int size;
public:
	SinglyLinkedList() : head{ nullptr }, size{ 0 } {}
	SinglyLinkedList(T data) : head{std::make_unique<single_node::Node<T>>(data) }, size{ 1 } {}

    void insertAtBeginning(T data) {
        std::unique_ptr<single_node::Node<T>> newNode = std::make_unique<single_node::Node<T>>(data);
        newNode->next = std::move(head);
        head = std::move(newNode);
        size++;
    }

    void insertAtEnd(T data) {
        std::unique_ptr<single_node::Node<T>> newNode = std::make_unique<single_node::Node<T>>(data);
        single_node::Node<T>* current = head.get();
        if (!current) {
            head = std::move(newNode);
            size++;
            return;
        }
        while (current->next) {
            current = current->next.get();
        }
        current->next = std::move(newNode);
        size++;
    }

    void removeFirst() {
        if (!head) throw std::out_of_range("Список пустий!");
        head = std::move(head->next);
        size--;
    }

    void removeLast() {
        if (!head) throw std::out_of_range("Список пустий!");
        if (size == 1) {
            head.reset();
            size--;
            return;
        }
        single_node::Node<T>* current = head.get();
        while (current->next->next) {
            current = current->next.get();
        }
        current->next.reset();
        size--;
    }

    T operator[](int index) {
        if (index < 0 || index > size - 1) throw std::out_of_range("Index is out of range");

        single_node::Node<T>* current = head.get();
        for (int i = 1; i <= index; i++) {
            current = current->next.get();
        }
        return current->data;
    }

    void insertAtIndex(T data, int index) {
        if (index == 0) {
            insertAtBeginning(data);
            return;
        }

        if (index == size) {
            insertAtEnd(data);
            return;
        }

        if (index < 0 || index > size - 1) throw std::out_of_range("Індекс виходить за межі діапазону");

        std::unique_ptr<single_node::Node<T>> newNode = std::make_unique<single_node::Node<T>>(data);
        single_node::Node<T>* previous = head.get();
        for (int i = 1; i <= index - 1; i++) {
            previous = previous->next.get();
        }
        newNode->next = std::move(previous->next);
        previous->next = std::move(newNode);
        size++;
    }

    void removeAtIndex(int index) {
        if (index < 0 || index > size - 1) throw std::out_of_range("Індекс виходить за межі діапазону");
        if (index == 0) {
            removeFirst();
            return;
        }
        if (index == size - 1) {
            removeLast();
            return;
        }
        single_node::Node<T>* previous = head.get();
        for (int i = 1; i <= index - 1; i++) {
            previous = previous->next.get();
        }
        previous->next = std::move(previous->next->next);
        size--;
    }
};

