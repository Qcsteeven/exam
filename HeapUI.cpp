#include <iostream>

#include "Heap.cpp"

int main() {
  std::cout << "Enter a size of arr: ";
  int size;
  std::cin >> size;
  std::cout << "Enter a numbers: ";
  int* arr = new int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> arr[i];
  }
  Heap heap(arr, size);
  std::cout << "Your heap: ";
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  while (true) {
    std::cout << "Enter commmand(push, pop_max, heap_sort, print): ";
    std::string str;
    std::cin >> str;
    if (str == "push") {
      std::cout << "Enter the value: ";
      int value;
      std::cin >> value;
      heap.Push(value);
    } else if (str == "pop_max") {
      heap.PopMax();
    } else if (str == "heap_sort") {
      std::cout << "Your heap: ";
      heap.HeapSort();
      std::cout << std::endl;
    } else if (str == "print") {
      std::cout << "Your heap: ";
      heap.Print();
      std::cout << std::endl;
    }
  }
}