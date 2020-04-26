#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
//
//using std::vector;
//using std::swap;

using namespace std;

pair<int,int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }

  swap(a[l], a[j]);

  int last = a[j];
  int m1=j,m2=j;
  while(m1>0)
  {
  if(a[m1-1]==last)
    m1--;
  else
    break;


  }

  return make_pair(m1,m2);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair<int, int> p = partition2(a, l, r);
  int m1 = p.first;
  int m2 = p.second;

  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];

  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
