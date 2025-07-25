#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

ll factorial(int N)
{
    if (N == 0)
        return 1;
    if (N == 1)
        return 1;
    return N * factorial(N - 1);
}
long long trailing_zeros(long long n)
{
    long long cnt = 0;
    for (long long p = 5; p <= n; p *= 5)
        cnt += n / p;
    return cnt;
}

int main()
{
    cin >> N;
    ll tmp = factorial(N);
    // cout << tmp << endl;
    // int cnt = 0;
    // while (tmp % 10 == 0)
    //{
    // cnt++;
    // tmp /= 10;
    //}
    // cout << cnt << endl;
    cout << trailing_zeros(N);

    return 0;
}