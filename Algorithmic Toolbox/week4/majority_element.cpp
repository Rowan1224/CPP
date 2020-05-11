#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int get_majority_element(vector<int> &a) {

    sort(a.begin(),a.end());
    int r = 0;
    int n = (a.size()/2)+1;
    int limit;
    if(a.size()%2 ==0)
    {
    limit = n-2;

    }
    else
    limit = n-1;
    for(int i =0;i<=limit;i++)
    {
//    cout<<a[i]<<" "<<a[i+limit-1]<<"\n";
    if(a[i]==a[i+n-1])
    {
    r =1;
    break;
    }

    }

  //write your code here
  return r;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a) << '\n';
}
