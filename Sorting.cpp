#include <iostream>

void SelectionSort(int*& arr, int size);
void InsertionSort(int*& arr, int size);
void BubbleSort(int*& arr, int size);

int main() {
  int* arr = new int[10]{5, 1, 2, 10, 4, 3, 2, 1, 7, 6};
  for (int i = 0; i < 10; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  BubbleSort(arr, 10);
  for (int i = 0; i < 10; ++i) {
    std::cout << arr[i] << " ";
  }
}

void BubbleSort(int*& arr, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
        if (arr[j] > arr[j + 1]) {
            std::swap(arr[j + 1], arr[j]);
        }
    }
  }
}

void InsertionSort(int*& arr, int size) {
  for (int i = 0; i < size; ++i) {
    int j = i + 1;
    while ((j > 0) && (arr[j - 1] > arr[j])) {
      std::swap(arr[j - 1], arr[j]);
      j--;
    }
  }
}

void SelectionSort(int*& arr, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (arr[j] < arr[i]) {
        std::swap(arr[j], arr[i]);
      }
    }
  }
}
