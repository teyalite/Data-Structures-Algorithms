/*
 * Copyright (C) 2021, Abdoulkader Abdourhamane Haidara.
 * Implementation of merge sort algorithm in C++ using Iterators.
 */

#include <iostream>
#include <iterator>
#include <vector>

template <typename InputIt1, typename InputIt2, typename OutputIt>
void Merge(InputIt1 begin_first, InputIt1 end_first, InputIt2 begin_second, InputIt2 end_second,
           OutputIt begin_output) {
    while (begin_first < end_first && begin_second < end_second) {
        if (*begin_first < *begin_second) {
            *begin_output = *begin_first;
            ++begin_first;
        } else {
            *begin_output = *begin_second;
            ++begin_second;
        }
        ++begin_output;
    }
    while (begin_first < end_first) {
        *begin_output = *begin_first;
        ++begin_first;
        ++begin_output;
    }
    while (begin_second < end_second) {
        *begin_output = *begin_second;
        ++begin_second;
        ++begin_output;
    }
}

template <typename RandomIt>
void Sort(RandomIt begin, RandomIt end) {
    if (begin != end && begin < end - 1) {
        typedef typename std::iterator_traits<RandomIt>::value_type ValueType;
        std::vector<ValueType> temp(std::distance(begin, end));
        auto middle = std::next(begin, std::distance(begin, end) / 2);
        Sort(begin, middle);
        Sort(middle, end);
        Merge(begin, middle, middle, end, temp.begin());
        std::copy(temp.begin(), temp.end(), begin);
    }
}

template <typename T>
void Sort(std::vector<T>& array) {
    Sort(array.begin(), array.end());
}


/*
 * This function is an array reader.
 * The first input line is the size of the array and the second line will be the array.
 * Ex:
 * 5
 * 5 4 1 2 3
 */
template <typename T>
std::vector<T> ReadArray() {
    size_t size;
    std::cin >> size;
    std::vector<T> array(size);
    for (size_t i = 0; i < array.size(); ++i) {
        std::cin >> array[i];
    }
    return array;
}

/*
 * This function print an array.
 */
template <typename T>
void PrintArray(std::vector<T>& array) {
    for (auto iterator = array.begin(); iterator != array.end(); ++iterator) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;
}

int main() {
    auto array = ReadArray<int>();
    Sort(array);
    PrintArray(array);
    return 0;
}