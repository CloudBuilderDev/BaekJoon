#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n; // 1 <= n <= 100000 if n^2 = 10,000,000,000 100억임 1초는 1억 연산 
              // 그렇다면 투 포인터로 한번의 반복문으로 돌린다면 연산 횟수가 어떻게 될까?
    vector<int> v(n);
    for(int i =0;i<n;i++) {
        cin >> v[i];
    }
    cin >> x; // 1 <= x <= 200000
    int p = 0;
    int q = n-1;
    sort(v.begin(),v.end());  // + NlogN

    int count =0;
    
    while(p != q) {  // + N*const ? 
        if(v[p]+ v[q] < x) p++;
        else if(v[p] + v[q] > x) q--;
        else{
            count++;
            p++;
        }
    }
    cout << count;
}

