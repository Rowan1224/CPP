#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;


int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int l1 = str1.size();
  int l2 = str2.size();
  int dp[l2+1][l1+1];
  for(int i=0;i<=l1;i++)
    dp[0][i] = i;
  for(int i=0;i<=l2;i++)
    dp[i][0] = i;

  for(int i=1;i<=l2;i++)
    for(int j=1;j<=l1;j++)
    {

    int a = dp[i-1][j-1];
    int b = dp[i-1][j];
    int c = dp[i][j-1];

    if(str1[j-1]==str2[i-1])
    {
    dp[i][j] = a;
    }
    else
    {
    dp[i][j] = min(a,min(b,c))+1;
    }

    }

  return dp[l2][l1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
