#include <vector>

/*
 * Merge function receives 2 input sequences and one output sequence:
 * First:    |d1| | | ... | | | | | |
 *            ^                    ^
 *            begin_first          end_first
 * Second:   |v1| | | ... | | | | | |
 *            ^                    ^
 *            begin_second         end_second
 * Output:   | ...
 *            ^
 *            begin_output
 *
 * You have to write the result of merge operation into Output sequence:
 * First:    |d1|d2| | ... | | | | | |
 *                  ^                 ^
 *                  begin_first       end_first
 * Second:   |v1|v2| | ... | | | | | |
 *                  ^                 ^
 *                  begin_second      end_second
 * Output:   |d1|v1|v2|d2|...
 *                        ^
 *                        begin_output
 *
 * ======================================================================
 * First:    |d1|d2|     ...      |dn|
 *                                     ^
 *                                     end_first
 *                                     begin_first
 * Second:   |v1|v2|     ...      |vn|
 *                                    ^
 *                                    end_second
 *                                    begin_second
 * Output:   |d1|v1|v2|d2|         ...         |vn|
 *                                                 ^
 *                                                 begin_output
 *
 * Use only < operator. To check if the sequence has ended compare the input
 * iterator with end iterator. Delete this comment before submitting.
 * */
template <typename InputIt1, typename InputIt2, typename OutputIt>
void Merge(InputIt1 begin_first, InputIt1 end_first, InputIt2 begin_second, InputIt2 end_second,
           OutputIt begin_output) {
    // You code goes here ...
}

/*
 * Sort function receives sequence and sorts it.
 * You have to use Merge function to implement MergeSort.
 * Delete this comment before submitting
 */
template <typename RandomIt>
void Sort(RandomIt begin, RandomIt end) {
    // You code goes here ...
}

template <typename T>
void Sort(std::vector<T>& array) {
    Sort(array.begin(), array.end());
}
