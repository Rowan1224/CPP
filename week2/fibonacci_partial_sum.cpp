#include <iostream>
#include<cstdlib>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    int sum =1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current%m;
        current = (tmp_previous%m + current%m)%m;
        sum = (sum+current)%m;

    }

    return sum%m;
}


int main() {
    long long n, m=10,p;
    std::cin >> n >>p;
    long long len = 60;
    if(n!=0)
        n--;
//    std::cout<<len<<"\n";
    long long sum = (get_fibonacci_huge_naive(p%len, m)-get_fibonacci_huge_naive(n%len, m));
    if(sum<10)
        sum = (sum+10)%10;
    std::cout << sum << '\n';
}
