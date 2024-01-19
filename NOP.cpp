#include <iostream>

template <typename T>
T Min(const T& x, const T& y) {
  return x > y ? y : x;
}

template <typename T>
T Max(const T& x, const T& y) {
  return x > y ? x : y;
}

struct PrevState {
  size_t i;
  size_t j;
};

int main() {
  size_t n, m;
  std::cin >> n;
  auto* first_seq = new int[n];

  for (size_t i = 0; i < n; ++i) {
    std::cin >> first_seq[i];
  }

  std::cin >> m;
  auto* second_seq = new int[m];
  for (size_t i = 0; i < m; ++i) {
    std::cin >> second_seq[i];
  }

  auto** dp = new int*[n + 1];
  auto** prev = new PrevState*[n + 1];
  dp[0] = new int[m + 1]{};
  prev[0] = new PrevState[m + 1];

  for (size_t i = 1; i < n + 1; ++i) {
    dp[i] = new int[m + 1];
    prev[i] = new PrevState[m + 1];
    dp[i][0] = 0;
  }

  for (size_t i = 1; i <= n; ++i) {
    for (size_t j = 1; j <= m; ++j) {
      if (first_seq[i - 1] == second_seq[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        prev[i][j] = {i - 1, j - 1};
      } else {
        if (dp[i][j - 1] > dp[i - 1][j]) {
          dp[i][j] = dp[i][j - 1];
          prev[i][j] = {i, j - 1};
        } else {
          dp[i][j] = dp[i - 1][j];
          prev[i][j] = {i - 1, j};
        }
      }
    }
  }

  auto* res = new int[Min(n, m)];
  size_t rl = 0;
  for (size_t i = n, j = m; i && j;) {
    const PrevState& cur = prev[i][j];
    if (cur.i == i - 1 && cur.j == j - 1) {
      res[rl] = first_seq[i - 1];
      ++rl;
    }
    i = cur.i;
    j = cur.j;
  }

  for (size_t i = 0; i < rl; ++i) {
    std::cout << res[rl - 1 - i] << " ";
  }
  std::cout << std::endl;

  for (size_t i = 0; i < n + 1; i++) {
    delete[] dp[i];
    delete[] prev[i];
  }

  delete[] res;
  delete[] dp;
  delete[] prev;
  delete[] first_seq;
  delete[] second_seq;
  return 0;
}