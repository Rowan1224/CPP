#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long strToint(string a)
{
   long long num = 0;
    for(int i =0;i<a.length();i++)
    {
   int d = int (a[i])-int ('0');
   num= num*10+ long(d);
    }

    return num;

}
struct comp
{
    bool operator () (const string& lhs, const string& rhs)
    {
    stringstream ret1,ret2;
    ret1 << lhs;
    ret1 << rhs;

    ret2 << rhs;
    ret2 << lhs;

    string a,b;
    ret1 >> a;
    ret2 >> b;

    if(strToint(a)>strToint(b)){
    return true;
    }
    else
    return false;

    }

};



string largest_number(vector<string> a) {
  //write your code here
  stringstream ret;

    sort(a.begin(),a.end(),comp{});
  for (size_t i = 0; i < a.size(); i++) {
//        cout<< a[i] <<"\n";
        ret << a[i];
    }


  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
