#include <vector>

template <typename T>
struct CustomComparator {
  bool operator()(const T& lhs, const T& rhs) {
    // Your code goes here ...
  }
};

/*
 * Merge function receives a vector and pointers to first elements
 * of subarrays to merge. Note, function work with half-intervals [a,b)!:
 * Array:    |a1| | | | ... |an|b1| ... ... |bn| | | | |
 *            ^                 ^               ^
 *            first_begin       first_end       second_end
 *                              ^
 *                              second_begin
 *
 *
 * You have to write the result of merge operation into
 * the original vector starting from begin_first:
 Array:    |a1|b1| | | ...  ...|an|bn| | | | |
 *          ^                         ^
 *          first_begin               second_end
 *
 * Delete this comment before submitting.
 */
template <typename T, typename Compare = CustomComparator<T>>
void Merge(std::vector<T>& array, size_t first_begin, size_t first_end, size_t second_begin, size_t second_end, Compare comp = Compare()) {
  // Your code goes here ...
}

/*
 * MergeSort function receives a vector half-interval [a, b) and sorts it.
 * You have to use Merge function to implement MergeSort.
 * Delete this comment before submitting
 */
template <typename T, typename Compare = CustomComparator<T>>
void MergeSort(std::vector<T>& array, size_t begin, size_t end, Compare comp = Compare()) {
  // Your code goes here ...
}

template <typename T, typename Compare = CustomComparator<T>>
void Sort(std::vector<T>& array) {
  // Merge sort works with half intervals [, )
  MergeSort(array, 0, array.size());
}
