#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using std::vector;
using namespace std;

int n;
int c = 0;
int get_change(int m,vector<int>&dp, vector<int>&bt) {

//    cout<<++c<<"\n";
    c++;
  if(m == n)
    return 0;

   if(m > n)
        return n+1;

  if(dp[m]!=-1)
        return dp[m];



  int a,d;
  int b = n+1, c = n+1;

//  if((m*2>n && m*3>n) || m>87324)
//    a = n-m;
//  else
//    a = get_change(m+1,dp,bt)+1;

//  if(m*2<=n)
//  b =  get_change(m*2,dp,bt)+1;
//  if(m*3<=n)
//  c =  get_change(m*3,dp,bt)+1;

 if(m+1==n){
    bt[m]=m+1;
    return 1;
    }

  a =  get_change((m+1)*2,dp,bt)+2;
  b =  get_change(m*2,dp,bt)+1;
  c =  get_change(m*3,dp,bt)+1;
  d =  get_change((m+1)*3,dp,bt)+2;


//  if((m*2>n && m*3>n))
//    a = n-m;
//  else
//    a = get_change(m+1,dp,bt)+1;

  int x = min(min(a,b),min(c,d));
  dp[m] = x;

  if(x==a)
  {

    bt[m] = m+1;
    bt[m+1] = (m+1)*2;
  }
  else if(x==b){

    bt[m] = m*2;

  }
  else if(x==c){

    bt[m] = m*3;

  }
  else{

  bt[m] = m+1;
  bt[m+1]= (m+1)*3;
  }
//  cout<<bt[m]<<" -";
  return dp[m];
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}


int main() {


  std::cin >> n;
   vector<int> dp(n);
    vector<int>bt(n);

  for(int i=0;i<n;i++)
  {
  dp[i] =-1;

  }
//  cout<<"hey";
  int s = get_change(1,dp,bt);
  cout<<s<<"\n";
//  cout<<c<<"\n";
  vector<int> sequence;

  sequence.push_back(1);
  int next= 1;
  while(s>0){
  int a = bt[next];
  sequence.push_back(a);
//    cout<<a<<" ";
  next = a;
  s--;

  }
//  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
