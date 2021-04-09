#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

/*
 * The code that you want to test
 */
template <class RandIt, class T>
bool BinarySearch(RandIt begin, RandIt end, const T& value) {
    while (begin < end) {
        auto middle = begin + std::distance(begin, end) / 2;
        if (*middle < value) {
            begin = middle + 2;  // Oops. There is a bug.
        } else if (*middle == value) {
            return true;
        } else {
            end = middle;
        }
    }
    return false;
}

/*
 * Brute force solution of the task. O(n) time instead of O(log(n)). But this solutions is very
 * simple.
 */
template <class ForwardIt, class T>
bool BruteForceSearch(ForwardIt begin, ForwardIt end, const T& value) {
    return std::find(begin, end, value) != end;
}

/*
 * In C++ we use random library to generate random numbers.
 *
 * From Stroustrup's PPP book:
 *   The standard library random number facilities are based on two fundamental notions:
 *   - Engines. An engine is a function object that generates a uniformly distributed sequence of
 *      integer values.
 *   - Distributions. A distribution is a function object that generates a sequence of values
 *      according to a mathematical formula given a sequence of values from an engine as inputs.
 *
 * https://en.cppreference.com/w/cpp/header/random
 */
std::vector<int> GenerateArray(size_t size, int min_value, int max_value) {
    // 43 is seed of generator. For the same seed, the same sequence of random numbers will be
    // generated.
    // I use static so that a new generator is not created every time the function is called.
    // Otherwise, the beginning of the sequences will be the same.
    static std::mt19937 generator{43};

    // Distribution. The generated numbers will be in the range [min_value, max_value].
    std::uniform_int_distribution distribution{min_value, max_value};

    std::vector<int> result(size);
    for (auto& value : result) {
        // To get a random value, we send a generator to the distribution.
        value = distribution(generator);
    }

    return result;
}

void CompareSolutions(const std::vector<int>& array, int search_value) {
    auto fast_solution = BinarySearch(array.begin(), array.end(), search_value);
    auto brute_solution = BruteForceSearch(array.begin(), array.end(), search_value);

    if (fast_solution != brute_solution) {
        std::cerr << "\nTest failed!" << std::endl << "Input data: ";
        std::for_each(array.begin(), array.end(), [](auto item) {
            std::cerr << item << " ";
        });
        std::cerr << "\nSearch value: " << search_value << std::endl;
        std::abort();
    }
}

void RunStressTest() {
    constexpr size_t kMinSize = 0;
    constexpr size_t kMaxSize = 30;

    constexpr int kMinValue = -1000;
    constexpr int kMaxValue = 1000;

    constexpr size_t kIterationCount = 100;

    std::mt19937 generator{42};

    std::uniform_int_distribution size_distribution{kMinSize, kMaxSize};
    std::uniform_int_distribution value_distribution{kMinValue, kMaxValue};

    std::cerr << "Completed iterations: ";
    for (size_t iteration = 0; iteration < kIterationCount; ++iteration) {
        auto array = GenerateArray(size_distribution(generator), kMinValue, kMaxValue);
        std::sort(array.begin(), array.end());

        std::cerr << iteration << " ";

        size_t check_count = size_distribution(generator);
        for (size_t current_check = 0; current_check < check_count; ++current_check) {
            CompareSolutions(array, value_distribution(generator));
        }
    }
    std::cerr << "\nTests passed!" << std::endl;
}

/*
 * In order to catch runtime-errors as well, run a stress test under ASAN.
 */
int main() {
    RunStressTest();
    return 0;
}
