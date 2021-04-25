#include <functional>

template <typename Key, typename T, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>>
class HashTable {
public:

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/unordered_map (1)
     *
     * Constructs new container. The number of buckets to create is implementation-defined.
     */
    HashTable();
    
    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/unordered_map (1)
     *
     * Constructs new container, uses bucket_count parameter as a minimal number of buckets to create.
     */
    explicit HashTable(size_t bucket_count);
    
    HashTable(const HashTable& other);

    ~HashTable();

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/empty
     *
     * Returns true if the tree is empty, false otherwise
     */
    bool Empty() const;

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/size
     *
     * Returns the number of elements in the container
     */
    size_t Size() const;

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/clear
     *
     * Erases all elements from the container.
     */
    void Clear();

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/insert
     * 
     * Returns a bool value set to true if the insertion took place.
     */
    bool Insert(const Key& key, const T& value);

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/erase
     *
     * Removes the element from the container with set key.
     * Returns true if the erase took place.
     */
    bool Erase(const Key& key);

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/contains
     *
     * Returns true if an element with key equivalent to value exists in the container.
     */
    bool Contains(const Key& key) const;

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/operator_at
     *
     * Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already exist.
     */
    T& operator[](const Key& key);

private:
    // Your code goes here ...
};
