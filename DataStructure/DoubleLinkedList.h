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
};

