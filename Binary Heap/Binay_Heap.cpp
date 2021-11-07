/*
 * Copyright (C) 2021, Abdoulkader Abdourhamane Haidara
 * Implementation of BinaryHeap.
 * The comparator is by default less which is will build a min heap.
 */

#include <iostream>
#include <map>
#include <vector>

template <typename ElementType, typename Compare = std::less<ElementType>>
class Heap {
public:
    explicit Heap(Compare comp = Compare()) : comp_{comp} {
    }

    void MakeHeap(const std::vector<ElementType>& array) {
        heap_ = array;
        for (size_t i = heap_.size() / 2; i > 0; --i) {
            SiftDown(i - 1);
        }
    }

    void Insert(const ElementType& element) {
        heap_.push_back(element);
        SiftUp(heap_.size() - 1);
    }

    ElementType RemoveFront() {
        ElementType temp = heap_[0];
        heap_[0] = heap_[heap_.size() - 1];
        heap_.pop_back();
        SiftDown(0);
        return temp;
    }

    const ElementType& GetFont() const {
        return heap_[0];
    }

private:
    void SiftUp(size_t index) {
        while (index > GetParent(index) && comp_(heap_[index], heap_[GetParent(index)])) {
            std::swap(heap_[index], heap_[GetParent(index)]);
            index = GetParent(index);
        }
    }

    void SiftDown(size_t index) {
        while (HasLeftChild(index)) {
            size_t left = GetLeftChild(index);
            size_t right = GetRightChild(index);
            size_t j = left;
            if (HasRightChild(index) && comp_(heap_[right], heap_[left])) {
                j = right;
            }
            if (comp_(heap_[index], heap_[j])) {
                break;
            }
            std::swap(heap_[index], heap_[j]);
            index = j;
        }
    }

    size_t GetLeftChild(size_t index) const {
        return 2 * index + 1;
    }

    size_t GetRightChild(size_t index) const {
        return 2 * index + 2;
    }

    size_t GetParent(size_t index) const {
        return (index + 1) / 2 - 1;
    }

    bool HasLeftChild(size_t index) const {
        return 2 * index + 1 < heap_.size();
    }

    bool HasRightChild(size_t index) const {
        return 2 * index + 2 < heap_.size();
    }

private:
    std::vector<ElementType> heap_;
    Compare comp_;
};

std::vector<int> ReadVector() {
    size_t size;
    std::cin >> size;
    std::vector<int> array(size);
    for (auto& value : array) {
        std::cin >> value;
    }
    return array;
}

/// Function that get inputs commands and process them
void ProcessInputData() {
    size_t number_of_commands;
    std::string command;
    Heap<int> heap;
    std::cin >> number_of_commands;
    for (auto i = number_of_commands; i > 0; --i) {
        std::cin >> command;
        if (command == "Insert") {
            int input_value;
            std::cin >> input_value;
            heap.Insert(input_value);
            std::cout << input_value << std::endl;
            continue;
        }
        if (command == "RemoveMin") {
            std::cout << heap.RemoveFront() << std::endl;
            continue;
        }
        if (command == "GetMin") {
            std::cout << heap.GetFont() << std::endl;
            continue;
        }
        if (command == "MakeHeap") {
            auto array = ReadVector();
            heap.MakeHeap(array);
            std::cout << "MakeHeap" << std::endl;
            continue;
        }
    }
}

int main() {
    ProcessInputData();
    return 0;
}
