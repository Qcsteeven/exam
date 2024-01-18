#include <iostream>
#include <cmath>

void SimpleDivisors();
void IsPrimary();
void SieveEratosthenes();

int main() {
    IsPrimary();
}

void SieveEratosthenes() {
    int num;
    std::cin >> num;
    int* arr = new int[num + 1]{};
    for (int i = 2; i <= num; ++i) {
        if (arr[i] == 0) {
            int k = 2;
            while(k*i <= num) {
                arr[k*i] = 1;
                ++k;
            }
        }
    }

    for (int i = 2; i <= num; ++i) {
        if (arr[i] == 0) {
            std::cout << i <<' ';
        }
    }

}

void IsPrimary() {
    int num;
    std::cin >> num;
    bool flag = true;
    for (int i = 2; i < sqrt(num) + 1; ++i) {
        if (num % i == 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

void SimpleDivisors() {
  int num;
  std::cin >> num;
  int i = 2;
  while (num != 1) {
    if (num % i == 0) {
      std::cout << i << ' ';
      num = num / i;
    } else {
      ++i;
    }
  }
}