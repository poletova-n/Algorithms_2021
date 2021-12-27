#include <iostream>
int main() {
  int n;
  std::cin >> n;
  if (std::cin.fail())
    std::cout << "err";
  return 0;
}
