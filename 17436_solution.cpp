#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll M;
vector<int> primes;
int main()
{
    cin >> N >> M;
    primes.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> primes[i];
    }
    ll result = 0;

    for (int i = 1; i < (1 << N); i++)
    {
        ll count = 0;
        ll tmp = 1;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                tmp *= primes[j];
                count++;
            }
        }
        if (count % 2 == 0)
        {
            result -= M / tmp;
        }
        else
        {
            result += M / tmp;
        }
    }
    cout << result;
    return 0;
}
