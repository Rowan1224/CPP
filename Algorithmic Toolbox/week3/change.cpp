#include <iostream>

int get_change(int m) {
  int x,y,z;
  x = m/10;
  m = m%10;
  y = m/5;
  m = m%5;
  z = m;
  int n = x+y+z;


  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
