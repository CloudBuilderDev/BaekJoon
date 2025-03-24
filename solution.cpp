#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K;
ll count(ll p);
ll search(ll K);
int main()
{
    cin >> K;
    ll result = search(K);
    cout << result;
}

ll search(ll K)
{
    ll left = 1;
    ll right = 2 * K;
    ll result;
    while (left < right)
    {
        ll mid = (left + right) / 2;
        if (count(mid) == K)
        {
            result = mid;
            break;
        }
        else if (count(mid) > K)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}
ll count(ll p)
{
    ll count = p;
    for (ll i = 2; i * i <= p; i++)
    {
        count -= p / (i * i);
    }
    return count;
}
