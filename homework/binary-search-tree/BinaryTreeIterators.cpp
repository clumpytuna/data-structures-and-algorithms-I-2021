#include <functional>
#include <iterator>
#include <utility>

/*
 * Please read the comments carefully and delete them before submitting the solution. Don't change
 * the interface.
 */

template <typename T, typename Compare = std::less<T>>
class BinaryTree {
    class Node;

public:
    /*
     * According to the requirements for an stl-compatible iterator, some types must be defined in
     * it, such as value_type and some others. By inheriting your iterator from std::iterator, you
     * save yourself the need to define these types in your class manually.
     *
     * See https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator
     * */
    class Iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
    public:
        /*
         * Decide which constructors are needed to implement the interface.
         */

        bool operator==(const Iterator& rhs) const;

        bool operator!=(const Iterator& rhs) const;

        /*
         * ++iterator; equivalent to iterator.operator++();
         * iterator++; equivalent to iterator.operator++(0);
         *
         * Same for decrement.
         */
        Iterator& operator++();

        Iterator operator++(int);

        Iterator& operator--();

        Iterator operator--(int);

        T& operator*();

        T* operator->();

    private:
        Node* node_;
    };

public:
    BinaryTree();

    BinaryTree(const BinaryTree& other);

    BinaryTree& operator=(BinaryTree other);

    ~BinaryTree();

    /*
     * See https://en.cppreference.com/w/cpp/container/set/empty
     *
     * Returns true if the tree is empty, false otherwise
     */
    bool Empty() const;

    /*
     * See https://en.cppreference.com/w/cpp/container/set/size
     *
     * Returns the number of vertices in the tree
     */
    size_t Size() const;

    /*
     * See https://en.cppreference.com/w/cpp/container/set/clear
     *
     * Erases all vertices from the container.
     */
    void Clear();

    /*
     * Finds the maximum depth of the tree
     */
    size_t MaxDepth() const;

    /*
     * See https://en.cppreference.com/w/cpp/container/set/insert
     *
     * Returns a pair consisting of an iterator to the inserted element (or to the element that
     * prevented the insertion) and a bool value set to true if the insertion took place.
     */
    std::pair<Iterator, bool> Insert(const T& value);

    /*
     * See https://en.cppreference.com/w/cpp/container/set/erase
     *
     * Removes the element at position.
     * Returns iterator following the last removed element.
     */
    Iterator Erase(Iterator position);

    /*
     * Finds an element with key equivalent to value.
     * Return iterator to an element with key equivalent to value. If no such element is found the
     * End() iterator is returned
     */
    Iterator Find(const T& value);

    Iterator Begin();

    /*
     * See https://en.cppreference.com/w/cpp/container/set/end
     *
     * Returns an iterator to the element following the last element
     */
    Iterator End();

    /*
     * range-based for loop:
     * for (auto& value : container) { ... }
     *
     * Range-based for only works with a collection if it has the begin() and end() methods,
     * That's why we additionally define these methods in a class with names that don't match the
     * style guide. However, clang-tidy will not allow you to make methods with such names, so use
     * the // NOLINT comment after the method header.
     *
     * The use of NOLINT in all other cases and tasks is PROHIBITED. In case of violation, the
     * points will be reset to zero.
     */
    Iterator end() {  // NOLINT
        return End();
    }

    Iterator begin() {  // NOLINT
        return Begin();
    }

private:
    struct Node {
        /*
         * Add a constructor for ease of use. Don't forget to initialize the pointers. Don't
         * complicate this structure. Its task is to store values and pointers.
         */

        T value;

        Node* parent;
        Node* left;
        Node* right;
    };

private:
    // Your code goes here ...
};

/*
 * Finds the successor of the value.
 * Returns an iterator to the successor of the value. If the value does not have the successor the
 * End() iterator is returned
 */
template <class T>
auto GetSuccessor(BinaryTree<T>& tree, const T& value);

/*
 * Finds the p-th smallest vertex in the tree.
 * Returns an iterator to the p-th smallest vertex.
 * If the p-th smallest vertex does not exist in the tree the End() iterator is returned
 */
template <class T>
auto PthSmallest(BinaryTree<T>& tree, size_t pth);

/*
 * For the remaining two tasks, try to come up with an interface yourself. Use iterators. When
 * implemented correctly, the functions should be very simple.
 */
