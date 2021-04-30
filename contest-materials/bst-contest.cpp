#include <iostream>
#include <string>

template <typename T, typename Compare = std::less<T>>
class BinaryTree {
private:
    struct Node;

public:
    ~BinaryTree() {
        Clear();
    }

    /*
     * See https://en.cppreference.com/w/cpp/container/set/clear
     *
     * Erases all vertices from the container.
     */
    void Clear() {
        ClearHelper(root_);
        root_ = nullptr;
    }

    /*
     * Returns a bool value set to true if the insertion took place.
     */
    bool Insert(const T& value) {
        if (root_ == nullptr) {
            root_ = new Node{.value = value};
            return true;
        }

        return InsertHelper(root_, value);
    }

    /*
     * Returns the sum of the leaves with the maximum depth
     *
     * Problem: BST: Go deeper
     */
    T DeepestVerticesSum() const {
        // Your code goes here ...
    }

    /*
     * Returns the sum of the vertices whose value belongs to a given range [left, right]
     *
     * Problem: BST: Required sum
     */
    T RangeSum(const T& left, const T& right) const {
        // Your code goes here ...
    }

private:
    void ClearHelper(Node* node) {
        if (node != nullptr) {
            ClearHelper(node->left);
            ClearHelper(node->right);
            delete node;
        }
    }

    bool InsertHelper(Node* node, const T& value) {
        while (true) {
            if (comp_(node->value, value)) {
                if (node->right != nullptr) {
                    node = node->right;
                } else {
                    node->right = new Node{.value = value, .parent = node};
                    return true;
                }
            } else if (comp_(value, node->value)) {
                if (node->left != nullptr) {
                    node = node->left;
                } else {
                    node->left = new Node{.value = value, .parent = node};
                    return true;
                }
            } else {
                return false;
            }
        }
    }

    struct Node {

        T value;

        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;
    };

private:
    Compare comp_;
    Node* root_ = nullptr;
};

void Solve() {
    // Line 1
    size_t n;
    // Line 2 - n + 1
    std::cin >> n;

    using ElementType = int32_t;
    BinaryTree<ElementType, std::less<ElementType>> binary_tree;
    ElementType value;
    for (size_t i = 0; i < n; i++) {
        std::string op;
        std::cin >> op;
        std::cin >> value;
        binary_tree.Insert(value);
    }

    // Uncomment the line corresponding to the problem being solved

    // Problem: BST: Go deeper
    // std::cout << binary_tree.DeepestVerticesSum();

    // Problem: BST: Required sum
    // ElementType left;
    // std::cin >> left;
    // ElementType right;
    // std::cin >> right;
    // std::cout << binary_tree.RangeSum();
}

int main() {
    Solve();
    return 0;
}
