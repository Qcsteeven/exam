#include <iostream>

int Min(int*& arr, int size);
int Max(int*& arr, int size);

int main() {
    int* arr = new int[10]{-100, 219, 1, -1238, 312, 321, 1 , 4, -666228, 2005};
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << "Minimum: " << Min(arr, 10) << '\n';
    std::cout << "Maximum: " << Max(arr, 10) << '\n';
}

int Min(int*& arr, int size) {
  int min = INT_MAX;
  for (int i = 0; i < size; ++i) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}
int Max(int*& arr, int size) {
  int max = INT_MIN;
  for (int i = 0; i < size; ++i) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}