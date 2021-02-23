
namespace task {

class List {
public:

    List();
    List(size_t count, const int& value = int());
    List& operator=(const List& other);
    ~List();

    int& Front() {
        // Your code goes here...
    }
    const int& Front() const {
        // Your code goes here...
    }
    int& Back();
    const int& Back() const;

    bool Empty() const;
    size_t Size() const;
    
    void Clear();
    void PushBack(const int& value);
    void PopBack();
    void PushFront(const int& value);
    void PopFront();
    void Resize(size_t count);

private:

    struct Node {
        // Your code goes here...
    };

    // Your code goes here...
};

class Stack {
public:

    Stack();
    Stack(const Stack& other);
    Stack& operator=( const Stack& other );
    ~Stack();

    int& Top() {
        // Your code goes here...
    }
    const int& Top() const {
        // Your code goes here...
    }

    bool Empty() const;
    size_t Size() const;

    void Push(const int& value);
    void Pop();
    void Clear();

private:
    List container;
};

} 

int main() {
    return 0;
}