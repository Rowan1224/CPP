#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;



vector<int> optimal_points(vector<pair<int,int>> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(),segments.end());
  for (size_t i = 0; i < segments.size(); ++i) {

    int cor = segments[i].second;
    int j;
    if(i+1< segments.size()){
        j = i+1;
    }
    else{
     points.push_back(cor);
     return points;
    }

    while(true)
    {
    int initial = segments[j].first;
    int end = segments[j].second;

    if(j>=segments.size())
    {
    i = j;
    points.push_back(cor);
    break;
    }

    if(initial>cor)
    {

    points.push_back(cor);
    i = j-1;
    break;

    }
    else{

    cor = min(end, cor);
    j++;

    }

    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<pair<int,int>> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].first >> segments[i].second;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
