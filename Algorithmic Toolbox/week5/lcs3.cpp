#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int lcs(vector<int>&a, vector<int>&b, int dp[101][101])
{

int l1=a.size(), l2=b.size();

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

}
int lcs2(vector<int>&a, vector<int>&b)
{

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

}
vector<int> backtrack(int dp[101][101], vector<int>a, vector<int>b){

    vector<int> d;
    int i=b.size(),j=a.size();
    while(i>0 && j>0){

    int x = dp[i][j];
    int y = dp[i-1][j-1];
    int w = dp[i-1][j];
    int z = dp[i][j-1];
    int u = max(w,z);
//    cout<< i <<" "<<j<<"\n";
    if(x-1==y && a[j-1]==b[i-1])
    {
    d.push_back(a[j-1]);
//    cout<<a[i]<<"\n";
    i = i-1;
    j = j-1;

    }
    else
    {
    if(u == w)
    {
    i = i-1;
    }
    else{
    j = j-1;
    }

    }


    }

    return d;

}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {


int dp[101][101][101];
//    int n = lcs(a,b,dp1);
//    vector<int> d = backtrack(dp1,a,b);
//    n = lcs(a,c,dp2);
//    vector<int> e = backtrack(dp2,a,c);
//    n = lcs(b,c,dp3);
//    vector<int> f = backtrack(dp3,b,c);
////    n = max(lcs(d,a,dp4),max(lcs(e,a,dp5));
//    reverse(d.begin(),d.end());
//    reverse(e.begin(),e.end());
//    reverse(f.begin(),f.end());
////    for(int i =0;i<d.size();i++)
////        cout<<d[i] <<" ";
////    cout<<"\n";
////    for(int i =0;i<e.size();i++)
////        cout<<e[i] <<" ";
////    cout<<"\n";
////    for(int i =0;i<f.size();i++)
////        cout<<f[i] <<" ";
////    cout<<"\n";
//    n = max(lcs2(d,c),max(lcs2(e,b),lcs2(f,a)));
//
//
//
//    return n;
    for(int i=0;i<=a.size();i++)
        for(int j=0;j<=b.size();j++)
            for(int k=0;k<=c.size();k++)
                {
                if(i==0||j==0||k==0)
                    {
                    dp[i][j][k] = 0;

                    }
                else if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
                {
                dp[i][j][k] = dp[i-1][j-1][k-1]+1;

                }
                else{
                dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);

                }

                }

 return dp[a.size()][b.size()][c.size()];

}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
