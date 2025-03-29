#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, C;
vector<ll> houses;
vector<ll> markedIndex;
pair<ll,ll> findNear(ll mid, vector<ll>& subArray, ll j1, ll j2);
ll computeDistance(ll j1, ll j2, ll index);
int main() { // 2*10^8
    cin >> N >> C;
    houses.resize(N);
    markedIndex.resize(N);

    for(int i =0 ;i<N;i++) {
        cin >> houses[i];  // 0<= x <= 10^9
    }
    sort(houses.begin(), houses.end());
    // 2<=N <= 2*10^5, 2<= C <= N
    markedIndex.push_back(0);
    markedIndex.push_back(N-1);
    ll adjacentDistance = houses[N-1] - houses[0];

    for(int i=0;i<C-2;i++) {
        sort(markedIndex.begin(), markedIndex.end());
        pair<ll,ll> tmp;
        for(int j = 0; j< markedIndex.size()-1;j++) {
            ll index1 = markedIndex[j]; ll index2 = markedIndex[j+1];
            ll mid = (houses[index1]+houses[index2]) /2;
            vector<ll> subArray(houses.begin()+index1,houses.begin()+index2+1);
            pair<ll,ll> candidate = findNear(mid,subArray, j,j+1);
            if(j==0){
                tmp = candidate;
            }
            else if(candidate.second >= tmp.second){
                tmp = candidate;
            }
        }
        markedIndex.push_back(tmp.first);`
        adjacentDistance = tmp.second;
    }
    cout << adjacentDistance;
    return 0;
}
pair<ll,ll> findNear(ll mid, vector<ll>& subArray, ll j1, ll j2) {
    auto it = lower_bound(subArray.begin(), subArray.end(), mid);
    ll index1 = it-subArray.begin();
    ll index2 = index1-1;
    ll index = abs(subArray[index1]-mid) <= abs(subArray[index2]-mid) ? index1 : index2;
    ll distance = computeDistance(j1, j2, index);
    pair<ll,ll> result(index,distance);
    return result;
}
ll computeDistance(ll j1, ll j2, ll index){
    ll tmp1 = abs(houses[j1]-houses[index]);
    ll tmp2 = abs(houses[j2]-houses[index]);
    return tmp1 <= tmp2 ? tmp1 : tmp2;
}
