#include <bits/stdc++.h>
using namespace std;
long long countN(int mid, vector<int>& LANs);

int main() { // 2*10^8
    int K; cin >> K; // 10^4 랜선 개수
    int N; cin >> N; // 10^6 만들어야 하는 랜선의 개수
    vector<int> LANs(K);
    int maxLength = 0;
    for(int i =0;i<K;i++) {
        cin >> LANs[i];  // LANs[i] <= 2^31-1 = 10^9
        maxLength = max(maxLength, LANs[i]);
    }

    long long left = 1; long long right = maxLength;
    long long mid;
    int ableMaxLength = 0;

    // total : 30 * 10^4
    while(left <= right) { // log10^9 = 9*3.32 = 30 
        mid = (left + right)/2;
        if(mid == 0) break;
        long long sum = countN(mid, LANs);  // 10^4
        if(sum < N) {
            right = mid -1;
        }else {
            ableMaxLength = mid;
            left = mid +1;
        }
    }
    cout << ableMaxLength;
    return 0;
}

long long countN(int mid, vector<int>& LANs) {
    long long N = 0; 
    for(int i =0;i<LANs.size();i++) { // K = 10^4
        N += LANs[i]/mid;  // if K=10^4, N=10^6, each LANs length = 10^9 then able overflow
        // ex) max N : integer= 10^9,  N = 10^9/5*10^8 = 2, 2 * 10^4 < 10^6
        // N = 10^9/ 25*10^7 =  무튼 오버플로 난다네... 
    }
    return N;
}
