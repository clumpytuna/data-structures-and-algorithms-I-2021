#include <cstdint>
#include <iostream>
#include <string>
#include <utility>

class List {
 public:
    List() :
        tail_(new Node) {
    }

    ~List() {
        while (tail_->next) {
            delete std::exchange(tail_->next, tail_->next->next);
        }
        delete tail_;
    }

    void PushBack(int32_t value) {
        Node* new_node = new Node(value);
        new_node->next = std::exchange(tail_->next, new_node);
    }

    void Print() {
        Node* it = tail_->next;
        while (it != nullptr) {
            std::cout << it->value;
            std::cout << ((it->next) ? " " : "");
            it = it->next;
        }
    }

    void Reverse() {
        // Reverses the order of the elements
        // You code goes here...
    }

 private:
    struct Node {
        Node* next = nullptr;
        int32_t value = -1;

        Node() = default;
        explicit Node(int32_t value) : value(value) {}
    };

    Node* tail_ = nullptr;
};
