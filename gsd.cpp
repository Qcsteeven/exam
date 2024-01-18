#include <iostream>

int GSDFirst(int a, int b);
int GSDSecond(int a, int b);

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << GSDFirst(a,b) << " - greatest common divisor the first way\n";
  std::cout << GSDSecond(a,b)<< " - greatest common divisor the second way\n";
  std::cout << (a*b) / GSDFirst(a,b) << " - the smallest common multiple\n";
  std::cout << "\nXD";
}

int GSDFirst(int a, int b) {
  while (a != 0 && b != 0) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
  if (a == 0) {
    return b;
  }
  return a;
}

int GSDSecond(int a, int b) {
  while (a != 0 && b != 0) {
    if (a > b) {
      a = a % b;
    } else {
      b = b % a;
    }
  }
  if (a == 0) {
    return b;
  }
  return a;
}