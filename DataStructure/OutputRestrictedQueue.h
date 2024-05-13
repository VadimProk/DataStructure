#pragma once
#include "Queue.h"

template <typename T>
class OutputRestrictedQueue: public Queue<T>{
public:
	OutputRestrictedQueue() {}
	OutputRestrictedQueue(T data) : Queue<T>(data) {}
	void pushFront(T data) { this->queue.insertAtBeginning(data); }
	void pushBack(T data) { this->queue.insertAtEnd(data); }
};

