#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// 1764
//  N,M<= 500,000 자연수
//  2*10^8
int N, M;
int main()
{
    cin >> N >> M;
    set<string> s;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    set<string> result;
    for (int i = 0; i < M; i++)
    {
        string tmp;
        cin >> tmp;
        if (s.find(tmp) != s.end())
        {
            result.insert(tmp);
        }
    }
    cout << result.size() << '\n';
    for (auto it = result.begin(); it != result.end(); ++it)
    {
        cout << *it << '\n';
    }

    return 0;
}