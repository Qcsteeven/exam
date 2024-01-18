#include <iostream>

bool BinarySearch(int*& arr, int size, int value);

int main() {
  int* arr = new int[10]{1, 5, 8, 9, 10, 11, 12, 23, 324, 1244};
  int val;
  while (true) {
    std::cin >> val;
    if (BinarySearch(arr, 10, val)) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
}

bool BinarySearch(int*& arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  int middle = (right - left) / 2 + left;
  bool flag = false;
  while (left < right - 1) {
    middle = (right - left) / 2 + left;
    if (value > arr[middle]) {
      left = middle;
    } else if (value < arr[middle]) {
      right = middle;
    } else {
      return true;
      break;
    }
  }
  if (arr[left] == value || arr[right] == value || flag) {
    return true;
  }
  return false;
}