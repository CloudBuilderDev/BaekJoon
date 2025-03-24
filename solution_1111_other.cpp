#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;  // 물통의 용량
    int n; // 수열의 길이
    cin >> x >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 각 가능한 초기 값에 대해 모든 작업을 수행한 후의 최종 값을 미리 계산
    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1];
        prefix[i] = min(prefix[i], x); // 물통의 용량을 초과할 수 없음
        prefix[i] = max(prefix[i], 0LL); // 0보다 작을 수 없음
    }

    int m; // 쿼리의 개수
    cin >> m;

    while (m--) {
        ll y; // 초기 물의 양
        cin >> y;

        y = min(y, x); // 초기 물을 물통 용량에 맞춤
        y = max(y, 0LL); // 초기 물을 0 이상으로 맞춤

        // y가 수열을 처리한 후 어디에 도달하는지 이진 탐색
        int idx = upper_bound(prefix.begin(), prefix.end(), y) - prefix.begin() - 1;
        cout << prefix[idx] << "\n";
    }

    return 0;
}
