#include <iostream>

long long int gcd_naive(long long int a, long long int b) {


    if(b==0)
        return a;
    else
        return gcd_naive(b,a%b);
}

long long lcm_naive(long long int a, long long int b) {


  return (long long) (a * b)/gcd_naive(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
