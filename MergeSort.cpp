#include <iostream>

void MergeSort(int* arr, int* arr_end);
void Merge(int* res, int* left, const int* left_end, int* right,
           const int* right_end);
void Copy(int* to, int* from, const int* from_end);

int main() {
  size_t n;
  std::cin >> n;
  int* arr = new int[n];
  for (size_t i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  MergeSort(arr, arr + n);

  for (size_t i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;
  delete[] arr;
  return 0;
}

void MergeSort(int* arr, int* arr_end) {
  int size = arr_end - arr;

  if (size < 2) {
    return;
  }

  int* clone = new int[size];
  int* clone_end = clone + size;
  int* mid = clone + (size / 2);
  Copy(clone, arr, arr_end);

  MergeSort(clone, mid);
  MergeSort(mid, clone_end);

  Merge(arr, clone, mid, mid, clone_end);

  delete[] clone;
}

void Merge(int* res, int* left, const int* left_end, int* right,
           const int* right_end) {
  while (left != left_end && right != right_end) {
    if (*left <= *right) {
      *(res++) = *(left++);
    } else {
      *(res++) = *(right++);
    }
  }
  while (left != left_end) {
    *(res++) = *(left++);
  }
  while (right != right_end) {
    *(res++) = *(right++);
  }
}

void Copy(int* to, int* from, const int* from_end) {
  while (from != from_end) {
    *(to++) = *(from++);
  }
}