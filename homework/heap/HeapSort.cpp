#include <vector>

template <typename T, typename Compare = std::greater<T>>
class HeapSort {
public:
    explicit HeapSort(Compare comp = Compare()) : comp_{comp} {
    }

    // Function get a vector by reference and sort it.
    void operator()(std::vector<T>& array) {
        // Your code goes here
    }

private:
    // Make a heap on an array in O(n)
    void MakeHeap(std::vector<T>& array) {
        // Your code goes here
    }

    // Push the element in position index up
    void SiftDown(std::vector<T>& array, size_t index, size_t heap_size) {
        // Your code goes here ...
    }

    size_t GetLeftChild(size_t index) const {
        return 2 * index + 1;
    }

    size_t GetRightChild(size_t index) const {
        return 2 * index + 2;
    }

    size_t GetParent(size_t index) const {
        return (index + 1) / 2 - 1;
    }

    bool HasLeftChild(size_t index, size_t heap_size) const {
        return 2 * index + 1 < heap_size;
    }

    bool HasRightChild(size_t index, size_t heap_size) const {
        return 2 * index + 2 < heap_size;
    }

private:
    Compare comp_;
};