#include <iostream>
#include <vector>
#include<algorithm>
#include <map>
//using std::vector;
using namespace std;
bool sortbysec( pair<long long,long long> a,  pair<long long,long long> b)
{
    return (a.second < b.second);
}

long long binary_search_points(const vector<pair<long long, long long>> &a, pair<long long, long long> x) {

  long long left = 0, right = (long long)(a.size()-1);
  long long c1, c2;
  while(left<=right){

//    cout<<left<<" "<<right<<"\n";
    long long mid = left+(right-left)/2;

    if(a[mid].first==x.first && a[mid].second==x.second)
        return mid;

    if(a[mid].first>x.first){
    right = mid-1;

    }
    else{
    left = mid+1;
    }

  }

return -1;
  //write your code here
}



vector<long long> fast_count_segments( vector<pair<long long ,long long>> starts,vector<long long > points) {

  long long s = (long long)starts.size();
  vector<long long> result(points.size());
  map<long long ,long long> cnt;



  long long c = 0;
  for(long long i=0;i<s;i++)
  {
  long long b= starts[i].second;
  if(b==1)
    c++;
  else if(b==3)
    c--;
  else{
  cnt.insert(make_pair(starts[i].first, c));
  }
//  cnt[i] = c;



  }

  for(long long i=0;i<points.size();i++)
  {
//  long long p = binary_search_points(starts,make_pair(points[i],2));
  result[i] = cnt[points[i]];

  }



  return result;

}

vector<long long > naive_count_segments(vector<pair<long long ,long long >> starts, vector<long long> points) {
  vector<long long> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
    if(starts[j].first <= points[i] &&  starts[j].second >= points[i])
      cnt[i] += 1;
    }
  }
  return cnt;
}

int main() {
  long long n, m, k=0;
  std::cin >> n >> m;
  vector<pair<long long ,long long>> starts((2*n)+m);
  for (size_t i = 0; i < n; i++) {
//    std::cin >> starts[i] >> ends[i];
    long long a,b;
    cin>> a>> b;
    starts[k]=(make_pair(a,1));
    starts[k+1]= (make_pair(b,3));
    k+=2;
  }


  vector<long long > points(m);



  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
   starts[k]=(make_pair(points[i],2));
   k++;
  }

    sort(starts.begin(),starts.end());


//  use fast_count_segments
  vector<long long > cnt = fast_count_segments(starts,points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }



}
