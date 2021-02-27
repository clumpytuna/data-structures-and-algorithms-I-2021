class Stack {
 public:
    Stack() {
        // Initialize an empty stack
    }

    Stack(const Stack& other) {
        // Copies data from "other" stack into "this" stack (on initialization)
    }

    Stack& operator=(const Stack& other) {
        // Copy data from "other" stack into "this" stack (on assignment)
    }

    ~Stack() {
        // Releases resources
    }

    int Top() {
        // Returns last added element
    }

    bool Empty() const {
        // Returns whether the stack has no elements
    }

    size_t Size() const {
        // Returns the number of elements
    }

    void Push(int value) {
        // Inserts an element at the top
    }

    void Pop() {
        // Removes last added element
    }

    void Clear() {
        // Removes all elements from the stack
    }

 private:
    struct Node {
        // Your code goes here...
    };

    // Your code goes here...
};

int main() {
    return 0;
}
