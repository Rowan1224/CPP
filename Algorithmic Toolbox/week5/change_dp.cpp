#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int dp[10000][1] ={-1};

int get_change(int m) {
//
//    cout<<m<<"\n";
  if(m == 0)
    return 0;

   if(m < 0)
        return 99999;

  if(dp[m][0]!=-1)
        return dp[m][0];

  int a =  get_change(m-1)+1;
  int b =  get_change(m-3)+1;
  int c =  get_change(m-4)+1;
  dp[m][0] = min(min(a,b),c);

  return dp[m][0];
}

int main() {
  int m;
  std::cin >> m;
for(int i =0;i<=m;i++)
{
    dp[i][0]=-1;

}
  std::cout << get_change(m) << '\n';
}
