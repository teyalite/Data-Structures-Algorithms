/*
 * Copyright (C) 2021, Abdoulkader Abdourhamane Haidara
 * Implementation of Quick sort with none random pivot.
 * It contains three main functions: Sort, Partition, SelectPivot.
 */
#include <iostream>
#include <vector>

template <typename T>
struct CustomComparator {
    bool operator()(const T& lhs, const T& rhs) {
        return lhs <= rhs;
    }
};

size_t SelectPivot(size_t left, size_t right) {
    /// Pivot selection is not randomised
    return left;
}

template <typename T, typename Compare = CustomComparator<T>>
size_t Partition(std::vector<T>& vec, size_t left, size_t right, Compare comp = Compare()) {
    size_t pivot_index = SelectPivot(left, right);
    size_t index = left;
    for (size_t i = left + 1; i < right; i++) {
        if (comp(vec[i], vec[pivot_index])) {
            index++;
            std::swap(vec[index], vec[i]);
        }
    }
    std::swap(vec[index], vec[pivot_index]);
    return index;
}

/// Divide and conquer
template <typename T, typename Compare = CustomComparator<T>>
void Sort(std::vector<T>& vec, size_t left, size_t right, Compare comp = Compare()) {
    if (left < right) {
        size_t index = Partition(vec, left, right);
        Sort(vec, index + 1, right);
        Sort(vec, left, index);
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
    Sort<int>(array, 0, array.size());
    PrintArray(array);
    return 0;
}