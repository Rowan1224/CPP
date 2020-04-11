#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    int len =0;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current%m;
        current = (tmp_previous%m + current%m)%m;
//         std::cout << current%m << '\n';
//        if(previous%m==0 && current%m==1)
//        {
//        std::cout << ++len<< '\n';
//        break;
//        }
//        else
//            len++;

    }

    return current%m;
}

long long get_fibonacci_huge_len(long long m) {


    long long previous = 0;
    long long current  = 1;
    long long len =0;

    for (long long i = 0; ; ++i) {
        long long tmp_previous = previous;
        previous = current%m;
        current = (tmp_previous%m + current%m)%m;
//         std::cout << current%m << '\n';
        if(previous%m==0 && current%m==1)
        {
        len++;
        break;
        }
        else
            len++;

    }

    return len;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    long long len = get_fibonacci_huge_len(m);
//    std::cout<<len<<"\n";
    std::cout << get_fibonacci_huge_naive(n%len, m) << '\n';
}
