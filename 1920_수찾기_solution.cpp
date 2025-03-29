#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;

int exist(int i, vector<int>& v) {
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // 오버플로우 방지
        if (v[mid] == i) return 1;
        else if (v[mid] > i) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i]; 
    }

    int M;
    cin >> M;
    vector<int> v2(M);
    for (int i = 0; i < M; i++) {
        cin >> v2[i];
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < M; i++) {
        cout << exist(v2[i], v) << '\n';
    }

    return 0;
}
