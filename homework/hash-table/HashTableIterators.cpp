#include <functional>
#include <utility>

template <typename Key, typename T, typename Hash = std::hash<Key>,
          typename KeyEqual = std::equal_to<Key>>
class HashTable {
public:
    /*
     * See https://en.cppreference.com/w/cpp/named_req/ForwardIterator.
     */
    class Iterator : public std::iterator<std::forward_iterator_tag, std::pair<Key, T>> {
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
         */
        Iterator& operator++();

        Iterator operator++(int);

        T& operator*();

        T* operator->();

    private:
        // Your code goes here ...
    };

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/unordered_map (1)
     *
     * Constructs new container. The number of buckets to create is implementation-defined.
     */
    HashTable();

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/unordered_map (1)
     *
     * Constructs new container, uses bucket_count parameter as a minimal number of buckets to
     * create.
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
     * See https://en.cppreference.com/w/cpp/container/unordered_map/operator_at
     *
     * Returns a reference to the value that is mapped to a key equivalent to key, performing an
     * insertion if such key does not already exist.
     */
    T& operator[](const Key& key);

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/insert
     *
     * Returns a bool value set to true if the insertion took place.
     */
    std::pair<Iterator, bool> Insert(const Key& key, const T& value);

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/erase
     *
     * Removes the element at position.
     * Returns iterator following the last removed element.
     */
    Iterator Erase(Iterator position);

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/find
     *
     * Finds an element with key.
     * Return iterator to an element with key. If no such element is found the
     * End() iterator is returned
     */
    Iterator Find(const Key& key);

    Iterator Begin();

    /*
     * See https://en.cppreference.com/w/cpp/container/unordered_map/end
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
    // Your code goes here ...
};
