#include <iostream>
#include <algorithm>
#include <cmath>
int main() {
  int size;
  std::cin >> size;
  int log = log2(size) + 1;
  int* data = new int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> data[i];
  }
  int** SparseTable = new int*[size];
  for (int i = 0; i < size; ++i) {
    SparseTable[i] = new int[log];
  }
  for (int i = 0; i < size; ++i) {
    SparseTable[i][0] = data[i];
  }
  for (int j = 1; (1 << j) <= size; ++j) {
    for (int i = 0; i + (1 << j) <= size; ++i) {
      SparseTable[i][j] = std::min(SparseTable[i][j - 1], SparseTable[i + (1 << (j - 1))][j - 1]);
    }
  }
  // TODO: Поиск минимума на отрезке
  int left;
  int right;
  while (true) {
    std::cin >> left >> right;
    int k = floor(log2(right - left + 1));
    std::cout << "Minimum in range [L, K] is " << std::min(SparseTable[left][k], SparseTable[right - (1 << k) + 1][k]);
  }
}