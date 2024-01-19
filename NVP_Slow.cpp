#include <iostream>
int main() {
  int size;
  std::cin >> size;
  auto arr = new int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> arr[i];
  }
  auto answer_arr = new int[size]{1};
  auto prev = new int[size];
  for (int i = 1; i < size; ++i) {
    answer_arr[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (arr[j] < arr[i] && answer_arr[j] >= answer_arr[i]) {
        answer_arr[i] = answer_arr[j] + 1;
        prev[i] = j;
      }
    }
  }
  int max = answer_arr[0], position = 0;
  for (int i = 0; i < size; ++i) {
    if (answer_arr[i] > max) {
      max = answer_arr[i];
      position = i;
    }
  }
  auto new_arr = new int[max];
  for (int i = 0; i < max; ++i) {
    new_arr[i] = arr[position];
    position = prev[position];
  }
  for (int i = max - 1; i >= 0; --i) {
    std::cout << new_arr[i] << " ";
  }
  delete[] arr;
  delete[] prev;
  delete[] new_arr;
  delete[] answer_arr;
}