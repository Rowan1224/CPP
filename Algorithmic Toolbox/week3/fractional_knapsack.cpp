#include <iostream>
#include <vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  map<double, int, greater<double> > unit;
  for(int i =0;i<weights.size();i++)
  {
  double u = double((double)values[i]/(double)weights[i]);
  unit.insert(make_pair(u,i));

  }
  map<double, int>:: iterator it;
  for(it=unit.begin();it!=unit.end();++it)
  {

    double u = (*it).first;
    int index =(*it).second;

//    cout << u << " " << index<<"\n";


    int w = weights[index];
    if(w>=capacity){
    double v = u*(double)(capacity);
    value+=v;
    capacity=0;

    }
    else{
     double v = u*(double)w;
    value+=v;
    capacity=capacity-w;

    }
    if(capacity <=0)
        break;

  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(5);
//  std::cout << optimal_value << std::endl;
  printf("%.4lf",optimal_value);
  return 0;
}
