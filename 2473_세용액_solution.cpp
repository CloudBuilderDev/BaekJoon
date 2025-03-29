#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;  // max 5000 so n^2 = 25000,000 able 1 sencond

    vector<ll> v(N); // int 형은 대략 20억대까지 저장 가능 문제에서 저장되는 수는 1,000,000,000 10억이다. 
                     // 하지만 뭔가 불안하니 ll로 하자... 아!! 세 수를 더하니 30억이 될 수도 있다. 그러니 ll로 꼭 해야한다.
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    // ll currentest = abs(INT_MAX);  잘 생각해보면 10억으로 도배된 경우 30억이 최적해인데 INT_MAX하면 안되겠구나..
    ll currentest = abs(LONG_LONG_MAX);
    ll save[3];

    for(int i =0; i<N-2;i++) {
        int p = i+1;
        int q = N-1;

        while(p<q) {
            ll sum = v[i] + v[p] + v[q];
            if(currentest > abs(sum)) {
                save[0] = v[i];
                save[1] = v[p];
                save[2] = v[q];
                currentest = abs(sum);
            }
            if(sum < 0) {
                p++;
            } else if(sum > 0) {
                q--;
            }
            else {
                break;
            }
        }
    }

    cout << save[0] << ' '<< save[1] << ' ' << save[2];
    return 0;
}

    // 반복문 두번 해도 되니 깔끔하게 쭉 순회하는게 좋지 이렇게 할 필요 없는 것 같다. 
    // 명시된 성능 조건을 보고 쓸 수 있는 자원을 써서 깔끔하고 완벽하게 의도한 동작을 수행하도록 해야한다. 
    // 반례 : 6
    //      -100 -2 -1 3 98 100
    //       -2 -1 3
    // while(p !=q) {
    //     int sum = v[p] + v[q];
    //     int r = p+1;
    //     for(;r<q;r++) {
    //         sum = sum+v[r];
    //         if(currentest >= abs(sum)) {
    //             currentest = abs(sum);
    //             save[0] = v[p];
    //             save[2] = v[q];
    //             save[1] = v[r];
    //         }
    //         sum -= v[r];
    //     }
    //     if(sum > 0) {
    //          q--;
    //       }
    //       else if(sum < 0) {
    //        p++;
    //     }else{
    //         break;
    //     }
    // }