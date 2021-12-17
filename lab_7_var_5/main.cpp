#include "String.hpp"
#include "Subscriber.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

std::size_t uniq(Subscriber *s, Subscriber *e) {
  std::size_t count = 0;
  bool isUniq = true;
  for (Subscriber *i = s; i != e; i++) {
    isUniq = true;
    for (Subscriber *j = s; j != e; j++) {
      if (i != j && i->name() == j->name() && i->surname() == j->surname())
        isUniq = false;
    }
    count += isUniq;
  }
  return count;
}
std::size_t count_numbers(Subscriber *s, Subscriber *e) {
  std::size_t count = 0;
  string a, b;
  bool isFound = false;
  for (Subscriber *i = s; i != e; i++) {
    isFound = false;
    for (Subscriber *j = i; j != e; j++) {
      if (i != j && i->number() != j->number() && i->name() == j->name() &&
          i->surname() == j->surname())
        isFound = true;
    }
    count += isFound;
  }
  return count;
}
bool comp(Subscriber &a, Subscriber &b) {
  String t1 = a.surname() + a.name() + a.code() + a.number();
  String t2 = b.surname() + b.name() + b.code() + b.number();
  return t1 > t2;
}
void sort(Subscriber *s, Subscriber *e) {
  Subscriber *min;
  for (auto i = s; i != e; i++) {
    min = i;
    for (auto j = i; j != e; j++) {
      if (comp(*j, *min))
        min = j;
    }
    swap(i, min);
  }
}
int main() {
  freopen("inp.txt", "r", stdin);
  int n;
  cin >> n;
  Subscriber *s = new Subscriber[n];
  String a, b, c, d;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c >> d;
    s[i].surname(a);
    s[i].name(b);
    s[i].number(c);
    s[i].code(d);
    if (!s[i].check()) {
      cerr << "Error\n";
      return 0;
    }
  }
  sort(s, s + n);
  for (int i = 0; i < n; i++)
    cout << s[i] << '\n';
  cout << uniq(s, s + n) << '\n';
  cout << count_numbers(s, s + n) << '\n';
  return 0;
}
