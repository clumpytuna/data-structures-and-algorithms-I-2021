#include <functional>

template <typename T, typename Compare = std::less<T>>
class BinaryTree {
    struct Node;

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
     * Finds the successor of the value.
     * If the successor exists, returns a reference to the successor, otherwise
     * throws a std::runtime_error
     */
    T& GetSuccessor(const T& value);

    /*
     * Finds the p-th smallest vertex in the tree.
     * Returns a reference to the p-th smallest vertex.
     * If the p-th smallest vertex does not exist a std::runtime_error is thrown
     */
    T& PthSmallest(size_t pth);

    /*
     * Removes the vertices whose values do not belong to a range [left, right]
     */
    void Prune(const T& left, const T& right);

    /*
     * Finds the maximum depth of the tree
     */
    size_t MaxDepth() const;

    /*
     * Finds the maximum value in the tree
     * Returns a reference to the maximum value.
     * If there is no the maximum value in the tree a std::runtime_error is thrown
     */
    T& GetMax();

    /*
     * Returns a bool value set to true if the insertion took place.
     */
    bool Insert(const T& value);

    /*
     * Removes the element from tree with key equivalent to value.
     * Returns true if the erase took place.
     */
    bool Erase(const T& value);

    /*
     * Finds an element with key equivalent to value.
     */
    bool Contains(const T& value) const;

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
