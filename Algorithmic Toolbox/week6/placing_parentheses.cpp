#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>
#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::max;
using std::min;
using namespace std;

std::vector<std::vector<long long>> dpM(30, std::vector<long long>(30));
std::vector<std::vector<long long>> dpm(30, std::vector<long long>(30));
long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

pair<long long,long long> MinMax(int i,int j, string o){

    long long mx=numeric_limits<long long>::min(),mn = numeric_limits<long long>::max();

    for(int k=i; k<j;k++)
    {
        long long a = eval(dpM[i][k],dpM[k+1][j],o[k-1]);
        mx = max(mx,a);
        mn = min(mn,a);

        long long b = eval(dpm[i][k],dpm[k+1][j],o[k-1]);
        mx = max(mx,b);
        mn = min(mn,b);
//        if(i==1 && j==4)
//            cout<<a<<" "<<b<<endl;

    }

    return make_pair(mx,mn);
}

long long get_maximum_value(const string &exp) {
  //write your code here
  vector<long long> values(30);
  string op;
  int n =0;
  for(int i =0;i<exp.size();i++)
  {
  if(isdigit(exp[i]))
  {
  long long a = (exp[i]-'0');
  values[n] =a;
//  cout<<a<<endl;
  n++;
  }
  else
  op = op+exp[i];

  }
//  cout<<op<<"\n";
  //
//std::vector<std::vector<long long>> dp(n+1, std::vector<long long>(n+1));

    for(int i = 1;i<=n;i++)
    {
    dpm[i][i]=values[i-1];
    dpM[i][i]=values[i-1];
//    cout<<values[i-1]<<endl;
    }

    for(int s=1;s<=n-1;s++)
        for(int i=1;i<=n-s;i++)
            {
             int j = i+s;
             pair<long long,long long> val = MinMax(i,j,op);
             dpM[i][j] = val.first;
             dpm[i][j] = val.second;
//             cout<<i<<" "<<j<<endl;


            }
//    cout<<n<<endl;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            cout<<dpM[i][j] <<" ";
//            }
//        cout<<"\n";
//        }

  return max(dpm[1][n],dpM[1][n]);
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
