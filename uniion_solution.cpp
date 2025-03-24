
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    vector<int> pigeonNest(N + 1);
    for (int i = 1; i <= N; i++) {
        pigeonNest[i] = i;
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            cin >> a >> b;
            pigeonNest[a] = b;

        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            int rootA = uf.find(a);
            int rootB = uf.find(b);
            if (rootA != rootB) {
                swap(pigeonNest[rootA], pigeonNest[rootB]);
                uf.merge(a, b);
            }

        } else if (type == 3) {
            int a;
            cin >> a;
            cout << pigeonNest[uf.find(a)] << '\n';
        }
    }

    return 0;
}
