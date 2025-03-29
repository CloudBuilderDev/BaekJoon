#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countCombinations(int N, ll C, vector<int>& weights);
void generateSubsetSums(int index, long long sum, const vector<int>& arr, vector<long long>& subsetSums);

int main() { // 10^8
    int N; cin >> N; // N <= 30
    int C; cin >> C; // C < 10^9

    vector<int> weights(N);
    for(int i =0;i<N;i++) {
        cin >> weights[i];
    }

    cout << countCombinations(N, C, weights);  // 최악의 경우 2^30만큼 subset sum <= Capacity 연산을 해야 함
}


ll countCombinations(int N, ll C, vector<int>& weights){ 
    int half = N/2;  //  Meet in the middle 기법을 활용 -> 최악의 경우 2^15 + 2^15 = 2^16으로 < 10^8 임
    vector<int> groupA(weights.begin(), weights.begin()+half);
    vector<int> groupB(weights.begin()+half, weights.end());
    
    // 두 개의 그룹으로 나누어 각각의 서브셋 sum을 생성함
    vector<ll> sumA, sumB;

    // 부분집합 합은 DFS 방식으로 시간복잡도를 줄임
    generateSubsetSums(0, 0, groupA, sumA);
    generateSubsetSums(0, 0, groupB, sumB);

    // sumB 정렬
    sort(sumB.begin(), sumB.end());

    // sumA의 각 원소에 대해 sumB에서 이진 탐색 수행
    ll count = 0;
    for (ll sa : sumA) {
        count += upper_bound(sumB.begin(), sumB.end(), C - sa) - sumB.begin();
    }

    return count;
}


// 가능한 부분집합의 합을 저장하는 함수 (DFS 방식)
void generateSubsetSums(int index, long long sum, const vector<int>& arr, vector<long long>& subsetSums) {
    if (index == arr.size()) {  
        subsetSums.push_back(sum);  // 현재까지의 합을 저장
        return;
    }
    // 현재 원소를 포함하지 않는 경우
    generateSubsetSums(index + 1, sum, arr, subsetSums);
    // 현재 원소를 포함하는 경우
    generateSubsetSums(index + 1, sum + arr[index], arr, subsetSums);
}