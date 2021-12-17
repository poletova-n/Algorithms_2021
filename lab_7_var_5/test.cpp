#include "String.hpp"
// #include "Subscriber.hpp"
// #include "Vector.hpp"
#include <iostream>
using namespace std;
int main() {
  freopen("inp.txt", "r", stdin);
  String a, b, c, d;
  cin >> a >> a >> b >> c >> d;
  for (char c : a)
    cout << c << ' ';
  return 0;
}
