#include <bits/stdc++.h>
using namespace std;

//1초 == 1억 연산
int main() {
    int N; // 100000
    cin >> N;

    vector<int> v(N);
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int p = 0;
    int q = N-1;
    pair<int, int> p1;
    int currentZero = abs(INT_MAX);

    while(p != q) {
        
    int sum = v[p] + v[q];
    if(currentZero >= abs(sum)){
        p1.first = v[p];
        p1.second = v[q];
        currentZero = abs(sum); 
    }
    if(sum <= 0) {
        p++;
    }
    else if(sum >0) {
         q--;
        }
    }

    cout << p1.first << ' ' << p1.second;
}
