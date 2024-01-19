#include <iostream>

int GetMin(int* arr, int left, int right, int x, int leftx, int rightx);

int main() {
  int size;
  std::cin >> size;
  int* arr = new int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> arr[i];
  }
  int iter = 1;
  for (; iter < size; iter *= 2) {
  }
  int* seg_tree = new int[2 * iter - 1];
  int index = 0;
  for (int i = iter - 1; i < 2 * iter - 1; ++i, ++index) {
    if (index < size) {
      seg_tree[i] = arr[index];
    } else {
      seg_tree[i] = INT_MAX;
    }
  }
  for (int i = iter - 2; i >= 0; --i) {
    seg_tree[i] = std::min(seg_tree[2 * i + 1], seg_tree[2 * i + 2]);
  }
  for (int i = 0; i < iter * 2 - 1; ++i) {
    std::cout << seg_tree[i] << " ";
  }
  int left;
  int right;
  while (true) {
    std::cin >> left >> right;
    std::cout << "Minimum in range [L, R] is "
              << GetMin(seg_tree, left, right, 0, 0, iter) << std::endl;
  }
}
int GetMin(int* arr, int left, int right, int x, int leftx, int rightx) {
  if (left >= rightx || leftx >= right) {
    return INT_MAX;
  }
  if (leftx >= left && rightx <= right) {
    return arr[x];
  }

  int middle = (leftx + rightx) / 2;
  int middle1 = GetMin(arr, left, right, 2 * x + 1, leftx, middle);
  int middle2 = GetMin(arr, left, right, 2 * x + 2, middle, rightx);
  int result = std::min(middle1, middle2);
  return result;
}