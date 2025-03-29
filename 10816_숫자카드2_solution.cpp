#include <bits/stdc++.h>
using namespace std;
int N, M;

int countExistNum(int target, vector<int>& cards);
int main() { // 10 ^8
     cin >> N; // < 5 * 10 ^5
    vector<int> cards(N);
    for(int i=0;i<N;i++) {
        cin >> cards[i]; // -10^7 ~ 10^7, < int = 2^32 = (10^3) ^ 3
    }
    sort(cards.begin(),cards.end()); // NlogN => 대략 9 * 10^6 -- log2의10이 3.32라는 점을 암기했다면 쉽게 근사 가능

    cin >> M; // 5 * 10 ^5
    vector<int> targetNum(M);
    for(int i =0;i<M;i++) {
        cin >> targetNum[i];
    }
    for(int i =0;i<M;i++) {
        // cout << countExistNum(targetNum[i],cards) <<' '; 
        cout << upper_bound(cards.begin(),cards.end(),targetNum[i]) - lower_bound(cards.begin(),cards.end(),targetNum[i]) << ' ';
    }
    return 0;
}
int countExistNum(int target, vector<int>& cards) {
    int count = 0;
    int left = 0; int right = cards.size()-1;
    while(left <= right) {
        int mid = left + (right - left)/2;  // ex) left = 10^7-2, right = 10^7-1 then integer overflow able
        if(cards[mid] == target){
            int tmp = mid;
            while(tmp < N && cards[tmp]==target){
                count++;
                tmp++;
            }
            tmp = mid-1;
            while(tmp >=0 && cards[tmp]==target){
                count++;
                tmp--;
            }
            break;
        }
        else if(cards[mid] < target) left = mid +1;
        else if(cards[mid] > target) right = mid-1;
    }
    return count;
}