#include <iostream>
int main() {
  size_t size, capacity;
  std::cin >> capacity >> size;
  auto* weights = new size_t[size];
  auto* prices = new size_t[size];
  auto** dp = new size_t*[capacity + 1];
  for (size_t i = 0; i <= capacity; i++) {
    dp[i] = new size_t[size + 1]{};
  }
  for (size_t i = 0; i < size; ++i) {
    std::cin >> prices[i] >> weights[i];
  }
  for (size_t i = 1; i <= capacity; i++) {
    for (size_t j = 1; j <= size; j++) {
      dp[i][j] = dp[i][j - 1];
      if (weights[j - 1] <= i) {
        size_t t = dp[i - weights[j - 1]][j - 1] + prices[j - 1];
        if (t > dp[i][j]) {
          dp[i][j] = t;
        }
      }
    }
  }
  size_t totalWeight = 0;
  for (size_t i = size, w = capacity; i > 0; --i) {
    if (dp[w][i] != dp[w][i - 1]) {
      totalWeight += weights[i - 1];
      w -= weights[i - 1];
    }
  }
  std::cout << dp[capacity][size] << " " << totalWeight << "\n";
  for (size_t i = 0; i <= capacity; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
  delete[] weights;
  delete[] prices;
}