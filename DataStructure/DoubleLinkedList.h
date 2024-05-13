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

    void insertAtIndex(int index, T data) {
        if (index == 0) {
            insertAtBeginning(data);
            return;
        }
        if (index == size) {
            insertAtEnd(data);
            return;
        }
        if (index < 0 || index > size - 1) throw std::out_of_range("������ �������� �� ��� ��������");
        std::shared_ptr<double_node::Node<T>> newNode = std::make_shared<double_node::Node<T>>(data);
        std::shared_ptr<double_node::Node<T>> previous = head;
        for (int i = 1; i <= index - 1; i++) {
            previous = previous->next;
        }
        newNode->next = previous->next;
        newNode->prev = previous;
        previous->next->prev = newNode;
        previous->next = newNode;
        size++;
    }

    void removeAtIndex(int index) {
        if (index < 0 || index > size - 1) throw std::out_of_range("������ �������� �� ��� ��������");

        if (index == 0) {
            removeFirst();
            return;
        }
        if (index == size - 1) {
            removeLast();
            return;
        }
        double_node::Node<T>* current = head.get();
        for (int i = 1; i <= index; i++) {
            current = current->next.get();
        }
        current->prev.lock()->next = current->next;
        current->next->prev = current->prev;
        size--;
    }

    int getSize() const { return size; }

    bool isEmpty() const { return size == 0; }

    int find(T search) {
        double_node::Node<T>* current = head.get();
        int index = 0;
        while (current) {
            if (search == current->data) return index;
            current = current->next.get();
            index++;
        }
        return -1;
    }

    friend std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& list) {
        double_node::Node<T>* current = list.head.get();
        while (current) {
            os << current->data << " ";
            current = current->next.get();
        }
        os << std::endl;
        return os;
    }
};

