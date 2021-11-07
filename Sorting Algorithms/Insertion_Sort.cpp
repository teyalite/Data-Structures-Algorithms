/*
 * Copyright (C) 2021, Abdoulkader Abdourhamane Haidara.
 * Implementation of insertion sort algorithm in C++.
 */
#include <iostream>
#include <vector>

/*
 * This function is the main function for sorting.
 * A custom comparator can be passed as template argument to sort in different order.
 * The default sorting order is ascendant.
 */
template <typename T, typename Compare = std::less<T>>
void InsertionSort(std::vector<T>& array, Compare compare = Compare()) {
    for (size_t i = 0; i < array.size(); i++) {
        T value = array[i];
        size_t j = i;
        while (j > 0 && compare(value, array[j - 1])) {
            array[j] = array[j - 1];
            --j;
        }
        array[j] = value;
    }
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
    for (auto& value : array) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    auto array = ReadArray<int>();
    InsertionSort(array);
    PrintArray(array);
    return 0;
}