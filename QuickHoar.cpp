#include <iostream>

void QuickSort(int* arr, int* arr_end);
void PartitionHoar(int32_t* arr, const int32_t* arr_end, int32_t pivot,
                   int32_t** ppl, int32_t** ppe);
void Swap(int32_t* p_first, int32_t* p_second);
int main() {
  int size;
  std::cin >> size;
  int* arr = new int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> arr[i];
  }
  QuickSort(arr, arr + size);
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
}

void QuickSort(int* arr, int* arr_end) {
  int size = arr_end - arr;
  if (size < 2) {
    return;
  }
  if (arr_end <= arr) {
    return;
  }

  int* pe;
  int* pl;
  int pivot = *arr;
  PartitionHoar(arr, arr_end, pivot, &pl, &pe);
  QuickSort(arr, pl);
  QuickSort(pe, arr_end);
}

void PartitionHoar(int32_t* arr, const int32_t* arr_end, int32_t pivot,
                   int32_t** ppl, int32_t** ppe) {
  int32_t* pl = arr;
  int32_t* pe = arr;
  int32_t* pg = arr;
  while (pg != arr_end) {
    if (*pg < pivot) {
      Swap(pg, pl);
      Swap(pg, pe);
      ++pg;
      ++pe;
      ++pl;
    } else if (*pg > pivot) {
      ++pg;
    } else {
      Swap(pg, pe);
      ++pg;
      ++pe;
    }
  }
  *ppl = pl;
  *ppe = pe;
}

void Swap(int32_t* p_first, int32_t* p_second) {
  int32_t tmp = *p_first;
  *p_first = *p_second;
  *p_second = tmp;
}