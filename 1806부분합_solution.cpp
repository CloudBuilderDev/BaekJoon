#include <bits/stdc++.h>
using namespace std;

/*int main() {
    int N, S,Length;
    cin >> N >> S;
    Length = 0;

    vector<int> v(N);

    for(int i=0;i<N;i++) {
        cin >> v[i];
        if(v[i] >= S) Length = 1;
    }
    bool stop = false;
    
    for(;++Length<=N;) {
        for(int i =0;i<= N-Length;i++) {
            int sum =0;
            for(int j=0;j<Length;j++) {
                sum += v[i+j];
            }
            if(sum>=S){
                stop = true;
                break;
            }
        }
        if(stop) break;
    }
    if(stop){
        cout << Length;
    }else if(Length == 1) cout << 1;
    else cout << 0;
}
    */

int main () {
    int N, S, Length, sum, p, q;
    cin >> N >> S;

    vector<int> v(N);
    for(int i =0;i<N;i++) {
        cin >> v[i];
    }
    sum = v[0];
    p = 0;
    q = 0;
    Length = 1000000;
    bool exist = false;
    while (q<=p && p!=N)
    {
        if(sum >= S) {
            exist = true;
            Length = min(Length, p-q+1);
            sum -= v[q++]; 
        }
        else {
            sum += v[++p];
        }
    }
    if(exist) cout << Length;
    else cout << 0;
}