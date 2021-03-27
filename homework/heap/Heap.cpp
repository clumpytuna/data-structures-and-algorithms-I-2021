#include <map>
#include <vector>

template <typename ElementType, typename Compare = std::less<ElementType>>
class Heap {
public:
    explicit Heap(Compare comp = Compare()) : comp_{comp} {
    }

    // Build a heap in O(n) time from a vector
    void MakeHeap(const std::vector<ElementType>& array) {
        // Your code goes here ...
    }

    void Insert(const ElementType& element) {
        // Your code goes here ...
    }

    // Delete and return the minimum element from heap
    ElementType RemoveMin() {
        // Your code goes here ...
    }

    // Return the minimum element from heap
    const ElementType& GetMin() const {
        // Your code goes here ...
    }

private:
    // Push the element in position index up
    void SiftUp(size_t index) {
        // Your code goes here ...
    }

    // Push the element in position index down
    void SiftDown(size_t index) {
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

    bool HasLeftChild(size_t index) const {
        return 2 * index + 1 < heap_.size();
    }

    bool HasRightChild(size_t index) const {
        return 2 * index + 2 < heap_.size();
    }

private:
    std::vector<ElementType> heap_;
    Compare comp_;
};
