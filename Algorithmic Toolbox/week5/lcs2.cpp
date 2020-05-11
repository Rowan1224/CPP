#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using std::vector;
using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {

  int l1=a.size(), l2=b.size();
  int dp[l2+1][l1+1];
  for(int i=0;i<=l1;i++)
    dp[0][i] = 0;
  for(int i=0;i<=l2;i++)
    dp[i][0] = 0;

  for(int i=1;i<=l2;i++)
    for(int j=1;j<=l1;j++)
    {

    int x = dp[i-1][j-1];
    int y = dp[i-1][j];
    int z = dp[i][j-1];

    if(a[j-1]==b[i-1])
    {
    dp[i][j] = x+1;
    }
    else
    {
    dp[i][j] = max(y,z);
    }

    }

  return dp[l2][l1];
//  return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
