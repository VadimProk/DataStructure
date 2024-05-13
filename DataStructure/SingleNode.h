#pragma once
#include <memory>

namespace single_node {
    template<typename T>
    struct Node {
        T data;
        std::unique_ptr<Node<T>> next;
        Node(const T& value) : data{ value }, next{ nullptr } {};
    };
}


