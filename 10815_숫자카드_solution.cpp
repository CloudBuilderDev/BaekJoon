#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;             // 5 * 10^5
vector<int> cards; // - 10 ^7 ~ 10 ^7
int M;             // 5 * 10^5

int result(int num)
{
    int p = 0;
    int q = N - 1;

    while (p <= q)
    {
        int mid = (p + q) / 2;
        if (cards[mid] > num)
        {
            q = mid - 1;
        }
        else if (cards[mid] < num)
        {
            p = mid + 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int main() // 2 * 10^8
{
    cin >> N;
    cards.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());

    cin >> M;
    vector<int> nums(M);
    for (int i = 0; i < M; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < M; i++)
    {
        cout << result(nums[i]) << " ";
    }
    return 0;
}
