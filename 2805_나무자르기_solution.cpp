#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, H;
vector<ll> trees;

int main() {
    cin >> N >> M; 
    trees.resize(N);
    ll maxHeight = 0;
    for(int i =0;i<N;i++) {
        cin >> trees[i];
        maxHeight =  max(maxHeight, trees[i]);
    }
    int result = 0;
    ll left = 0; ll right = maxHeight;
    
    while(left < right) {
        ll mid = (left + right) / 2;
        
        ll sum = 0;
        for(int i =0 ;i < N;i++) {
            ll tmp = trees[i] - mid;
            if(tmp < 0) continue;
            else sum += tmp;
        }
        if(sum >= M) {
            result = mid;
            left = mid +1;
        }
        else if ( sum < M) {
            right = mid; // 왜 mid - 1이면 틀리는 걸까? result에 mid를 저장하는 과정에서 문제가 생긴다. 만약 이 조건문 수행 후 
            // 다음 반복에 mid - 1 이 먼저 결과로 저장되어 버린다. 
        }
    }
    cout << result;
    return 0;
}
