#include <iostream>

void QuickSort(int* arr, int* arr_end);
int* PartitionLomuto(int* arr, int* arr_end);
void Swap(int* p_first, int* p_second);

int main() {
  int size;
  std::cin >> size;
  int* arr = new int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> arr[i];
  }
  QuickSort(arr, arr + size - 1);
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
}

void QuickSort(int* arr, int* arr_end) {
  if (arr < arr_end) {
    int* pivot = PartitionLomuto(arr, arr_end);
    QuickSort(arr, pivot - 1);
    QuickSort(pivot + 1, arr_end);
  }
}

int* PartitionLomuto(int* arr, int* arr_end) {
  int* pivot = arr_end;
  int* pl = arr;
  for (int* pr = arr; pr < arr_end; ++pr) {
    if (*pr < *pivot) {
      Swap(pr, pl);
      pl++;
    }
  }
  Swap(pl, pivot);
  return pl;
}

void Swap(int* p_first, int* p_second) {
  int tmp = *p_first;
  *p_first = *p_second;
  *p_second = tmp;
}
