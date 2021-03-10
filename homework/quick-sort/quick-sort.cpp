#include <iostream>
#include <vector>

template <typename T>
struct CustomComparator {
    bool operator()(const T& lhs, const T& rhs) {
        // You code goes here ...
    }
};

template <typename T, typename Compare = CustomComparator<T>>
T SelectPivot(const std::vector<T>& vec, size_t left, size_t right, Compare comp = Compare()) {
    // You code goes here ...
}

template <typename T, typename Compare = CustomComparator<T>>
size_t Partition(std::vector<T>& vec, size_t left, size_t right, Compare comp = Compare()) {
    // You code goes here ...
}

template <typename T, typename Compare = CustomComparator<T>>
void Sort(std::vector<T>& vec, size_t left, size_t right, Compare comp = Compare()) {
    // You code goes here ...
}
