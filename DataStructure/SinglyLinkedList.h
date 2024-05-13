#pragma once
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
};

