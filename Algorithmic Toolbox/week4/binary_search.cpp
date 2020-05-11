#include <iostream>
#include <cassert>
#include <vector>
#include<algorithm>

using namespace std;

long long binary_search(const vector<long long> &a, long long x) {
  long long left = 0, right = (long long)a.size()-1;
  bool flag = false;
  while(left<=right){

    long long mid = left+(right-left)/2;
//    if(a[mid]==x) {
//     return mid;
//    }
    if(a[mid]>x){
    right = mid-1;

    }
    else{
    left = mid+1;
    }

  }
if(right!= -1 || a[right]==x)
right--;
return right;
  //write your code here
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < a.size(); i++) {
    std::cin >> a[i];
//    a[i] =i;
//    a.push_back(i);
  }
  long long m;
  std::cin >> m;
  vector<long long> b(m);
  for (long long i = 0; i < m; ++i) {
    std::cin >> b[i];
    std::cout << binary_search(a, b[i]) << '\n';
//    b[i] =i;
  }
//  sort(a.begin(),a.end());
//  for (long long i = 0; i < m; ++i) {
//    //replace with the call to binary_search when implemented
//
//  }
}
