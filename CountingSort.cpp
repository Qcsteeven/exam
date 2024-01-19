#include <iostream>

void CountingSortStable(int arr[], int size, int range);
void CountingSort(int arr[], int size, int range);
int main() {
  int size;
  std::cin >> size;
  int* arr = new int[size];
  int max_val = 0;
  for (int i = 0; i < size; ++i) {
    std::cin >> arr[i];
    if (arr[i] > max_val) {
      max_val = arr[i];
    }
  }
  CountingSort(arr, size, max_val);
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
}

void CountingSort(int arr[], int size, int range) {
  int* count = new int[range + 1]();

  for (int i = 0; i < size; ++i) {
    count[arr[i]]++;
  }

  int index = 0;
  for (int i = 0; i <= range; ++i) {
    while (count[i] > 0) {
      arr[index] = i;
      index++;
      count[i]--;
    }
  }

  delete[] count;
}

void CountingSortStable(int arr[], int size, int range) {
  int* count = new int[range + 1]();
  int* output = new int[size]();

  for (int i = 0; i < size; ++i) {
    count[arr[i]]++;
  }

  for (int i = 1; i <= range; ++i) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; --i) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  for (int i = 0; i < size; ++i) {
    arr[i] = output[i];
  }

  delete[] count;
  delete[] output;
}
