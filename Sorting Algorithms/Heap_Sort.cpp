/*
 * Copyright (C) 2021, Abdoulkader Abdourhamane Haidara
 * Implementation of heap sort.
 * By default it sorts in ascending order.
 */

#include <iostream>
#include <map>
#include <vector>

template <typename T, typename Compare = std::greater<T>>
class HeapSort {
public:
    explicit HeapSort(Compare comp = Compare()) : comp_{comp} {
    }

    // Function get a vector by reference and sort it.
    void operator()(std::vector<T>& array) {
        MakeHeap(array);
        for (size_t heap_size = array.size() - 1; heap_size > 0; heap_size--) {
            std::swap(array[0], array[heap_size]);
            SiftDown(array, 0, heap_size);
        }
    }

private:
    // Make a heap on an array in O(n)
    void MakeHeap(std::vector<T>& array) {
        for (size_t i = ((array.size() - 1) / 2) + 1; i > 0; i--) {
            SiftDown(array, i - 1, array.size());
        }
    }

    // Push the element in position index up
    void SiftDown(std::vector<T>& array, size_t index, size_t heap_size) {
        while (HasLeftChild(index, heap_size)) {
            size_t left = GetLeftChild(index);
            size_t right = GetRightChild(index);
            size_t j = left;

            if (HasRightChild(index, heap_size) && comp_(array[right], array[left])) {
                j = right;
            }

            if (!comp_(array[j], array[index])) {
                break;
            }

            std::swap(array[index], array[j]);
            index = j;
        }
    }

    size_t GetLeftChild(size_t index) const {
        return 2 * index + 1;
    }

    size_t GetRightChild(size_t index) const {
        return 2 * index + 2;
    }

    bool HasLeftChild(size_t index, size_t heap_size) const {
        return 2 * index + 1 < heap_size;
    }

    bool HasRightChild(size_t index, size_t heap_size) const {
        return 2 * index + 2 < heap_size;
    }

private:
    Compare comp_;
};

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
    HeapSort<int> heap_sort;
    heap_sort(array);
    PrintArray(array);
    return 0;
}
