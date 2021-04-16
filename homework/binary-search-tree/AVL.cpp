#include <functional>

template <typename T, typename Compare = std::less<T>>
class AVLBinaryTree {
    struct Node;

public:
    AVLBinaryTree();

    AVLBinaryTree(const AVLBinaryTree& other);

    AVLBinaryTree& operator=(AVLBinaryTree other);

    ~AVLBinaryTree();

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
     * Returns a bool value set to true if the insertion took place.
     */
    bool Insert(const T& value);

    /*
     * Finds an element with key equivalent to value.
     */
    bool Contains(const T& value) const;

private:
    
    /*
     * Applying this operation to node restores the AVLBinaryTree property of the tree
     */
    void Balance(Node* node);
    
    /*
        Moves the tree from state A to state B:
        Definition: for the vertex v[h] , "h" is the height of the subtree with the root v

        State A:

                  node[h]
               /          \ 
           v1[h-3]       v2[h-1]
                       /         \
                    v3[h-2]      v4[h-2]
        
        Problem: for the verticies v1 and v2 |h-3 - h-1| = 2 >= 1, the AVL tree property is violated 

        State B:

                   v2[h]
                /        \
          node[h-1]      v4[h-2]
          /          \
        v1[h-3]    v3[h-2]

        Result: for each pair of vertices (v1, v3) ; (node, v4) the  AVL tree property is held
    */

    void RotateLeft(Node* node);

    /*
        Moves the tree from state A to state B
     
        State A:

                       node[h]
                  /             \
              v1[h-1]           v2[h-3]
            /          \
        v3[h-2]        v4[h-2]


        Problem: for the verticies v1 and v2 |h-3 - h-1| = 2 >= 1, the AVL tree property is violated 

        State B:

                      v1[h]
                  /           \
              v3[h-2]          node[h-1]
                             /          \
                         v4[h-2]         v2[h-3]

        Result: for each pair of vertices (v2, v4) ; (node, v3) the  AVL tree property is held

    */
    void RotateRight(Node* node);

    /*
        Moves the tree from state A to state B, and then to state C:
        Definition: for the vertex v[h] , "h" is the height of the subtree with the root v

        State A:

                  node[h]
               /          \ 
           v1[h-3]       v2[h-1]
                       /         \
                    v3[h-2]      v4[h-3]
                  /         \
               v5[h-3]      v6[h-4]
        
        State B:

                     node[h]
                /               \ 
           v1[h-3]              v3[h-1]
                            /            \
                        v5[h-3]           v2[h-2]
                                       /        \
                                    v6[h-4]     v4[h-3]
        
        State C:
                              v3[h-1]
                        /                 \ 
                 node[h-2]                   v2[h-2]
               /            \             /                 \
           v1[h-3]           v5[h-3]   v6[h-4]            v4[h-3]
                  
    */
    void RotateRightLeft(Node* node);

    /*
        Moves the tree from state A to state B, and then to state C:
        Definition: for the vertex v[h] , "h" is the height of the subtree with the root v

        State A:

                        node[h]
                    /           \ 
                v1[h-1]         v2[h-3]
                /       \
            v4[h-3]        v3[h-2]     
                        /         \
                    v5[h-3]      v6[h-4]
        
        State B:
 
                            node[h]
                        /            \ 
                      v3[h-1]            v2[h-3]
                    /         \
                 v1[h-2]      v6 [h-4]   
                /    \     
            v4[h-3]  v5[h-3]          
        

        State C:
                         
                           v3[h-1] 
                    /                 \ 
                v1[h-2]                  node[h-2]
                /       \                 /      \
        v4[h-3]        v5[h-3]     v6[h-4]      v2[h-3]

    */
    void RotateLeftRight(Node* node);

    struct Node {
        /*
         * Add a constructor for ease of use. Don't forget to initialize the pointers. Don't
         * complicate this structure. Its task is to store values and pointers.
         */

        T value;

        size_t height;
        Node* parent;
        Node* left;
        Node* right;
    };

private:
    // Your code goes here ...
};