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
};

