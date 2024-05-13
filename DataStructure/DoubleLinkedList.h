#pragma once
#include <ostream>
#include "../DataStructure/DoubleNode.h"

template<typename T>
class DoubleLinkedList{
private:
	std::shared_ptr<double_node::Node<T>> head;
	std::shared_ptr<double_node::Node<T>> tail;
	int size;
public:
	DoubleLinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}
	DoubleLinkedList(T data) : head{ std::make_shared<double_node::Node<T>>(data) }, tail{ head }, size{ 1 } {}

    void insertAtBeginning(T data) {
        std::shared_ptr<double_node::Node<T>> newNode = std::make_shared<double_node::Node<T>>(data);

        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtEnd(T data) {
        std::shared_ptr<double_node::Node<T>> newNode = std::make_shared<double_node::Node<T>>(data);

        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void removeFirst() {
        if (!head) throw std::out_of_range("List is empty!");

        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev.reset();
        }
        size--;
    }

    void removeLast() {
        if (!tail) throw std::out_of_range("List is empty!");

        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev.lock();
            tail->next.reset();
        }
        size--;
    }
};

