#include <iostream>
#include <limits>
template <typename T>
size_t BinarySearch(const T* const arr, size_t size, const T& elem) {
  size_t left = 0;
  size_t right = size - 1;
  while (right - left > 1) {
    size_t middle = left + (right - left) / 2;
    if (arr[middle] < elem) {
      left = middle;
    } else {
      right = middle;
    }
  }
  return arr[left] >= elem ? left : right;
}

int main() {
  size_t n;
  std::cin >> n;
  auto* prev = new size_t[n];
  auto* dp = new int[n + 1];
  auto* pos = new size_t[n + 1];
  auto* arr = new int[n];
  size_t rl = 0;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  for (size_t i = 0; i < n + 1; ++i) {
    dp[i] = std::numeric_limits<int>::max();
  }
  dp[0] = std::numeric_limits<int>::min();
  pos[0] = 0;
  for (size_t i = 0; i < n; ++i) {
    size_t p = BinarySearch(dp, n + 1, arr[i]);
    if (dp[p - 1] < arr[i] && arr[i] < dp[p]) {
      dp[p] = arr[i];
      if (p > rl) {
        rl = p;
      }
      pos[p] = i;
      prev[i] = pos[p - 1];
    }
  }
  auto* res = new int[n];
  size_t cur_rl = 0;
  size_t cur = pos[rl];
  for (;;) {
    res[cur_rl++] = arr[cur];
    if (!cur) {
      break;
    }
    cur = prev[cur];
  }
  std::cout << rl;
  delete[] prev;
  delete[] dp;
  delete[] pos;
  delete[] arr;
  delete[] res;
}