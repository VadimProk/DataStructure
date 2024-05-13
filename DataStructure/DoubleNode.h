#pragma once
#include <memory>

namespace double_node {
    template<typename T>
    struct Node {
        T data;
        std::shared_ptr<Node<T>> next;
        std::weak_ptr<Node<T>> prev;
        Node(const T& value) : data{ value }, next{ nullptr } {};
    };
}

