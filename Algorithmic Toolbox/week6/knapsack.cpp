#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using std::vector;
using namespace std;



int n,W;
int res = 0;
int recursion(const vector<int> &val){

//
std::vector<std::vector<int>> dp(n+1, std::vector<int>(W+1));
//    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=W;j++)
        {
//            cout<<i<<" "<<j<<"\n";
            if(i==0||j==0)
                dp[i][j] = 0;

           else if(val[i-1]<=j)
            {
            int a = val[i-1];
            int b = a+dp[i-1][j-a];
            int c = dp[i-1][j];
            dp[i][j] = max(b,c);
            }
            else{
            dp[i][j] = dp[i-1][j];

            }


        }

       return dp[n][W];
}

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {

  std::cin >> W >> n;
  vector<int> values(n);
//  values.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i];
  }
//  cout<<n<<"\n";
//
//    for (int i = 0; i < 100001; i++) {
//            dp[i] = -1;
//  }
  int a = recursion(values);
  cout<<a<<"\n";
//  std::cout << optimal_weight(W, w) << '\n';
}
