#include <bits/stdc++.h>
using namespace std;

int parent[200002]; // 최대 2*10^5명까지 커버
int network_size[200002];

int find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

int unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        parent[y] = x;
        network_size[x] += network_size[y];
    }
    return network_size[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int F;
        cin >> F;

        map<string, int> name_to_id;
        int id = 0;

        for (int i = 0; i < 2 * F; i++)
        {
            parent[i] = i;
            network_size[i] = 1;
        }

        while (F--)
        {
            string a, b;
            cin >> a >> b;

            if (name_to_id.find(a) == name_to_id.end())
                name_to_id[a] = id++;
            if (name_to_id.find(b) == name_to_id.end())
                name_to_id[b] = id++;

            int size = unite(name_to_id[a], name_to_id[b]);
            cout << size << '\n';
        }
    }

    return 0;
}
