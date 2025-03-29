#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll P, K;
// vector<ll> primes;
// // limit 2* 10^9
// // K이하의 소수들의 두 쌍의 소수 곱들을 모두 구하여 그 중에 P가 있으면 bad
// // 2 = K = 10^6 이니 10^6 C 2 = 10^11 정도임
// // 다른 방법 없나...?
// // 일단 에라토네스의 체로 K이하의 소수 배열을 구하고 그 배열 위에서 이분 탐색을 하든 투 포인터 기법을 쓰든 하면 되지 않을까?

// // 어떤 두 소수의 곱인 P (4 ~ 10^100)이 주어지면 그 값이 어떤 두 소수로 이루어져있는지 알려면?

// vector<ll> generatePrimes(ll K) {
//     vector<ll> primes;
//     vector<bool> is_prime(K,true);
//     is_prime[0] = is_prime[1] = false;
//     for(ll i = 2; i*i <= K; i++) {
//         if(is_prime[i]) {
//             for ( ll j = i*i; j<= K; j+=i) {
//                 is_prime[j] = false;
//             }
//         }
//     }
//     for (ll i = 2; i <= K; i++) {
//         if (is_prime[i]) primes.push_back(i);
//     }
//     return primes;
// }

// int main() {
//     cin >> P >> K;
//     primes = generatePrimes(1000000);  // 거의 상수
//     ll p = 0, q = primes.size()-1;
//     int detect = 0;
//     pair<ll, ll> result;
//     while(p < q) { // 10^6
//         ll mul = primes[p] * primes[q];  // 오버플로우 남
//         if(mul < P) {
//             p++;
//         }
//         else if(mul > P) {
//             q--;
//         }
//         else{
//             result.first = primes[p];
//             result.second = primes[q];
//             break;
//         }
//     }
//     if(result.first < K || result.second < K) {
//         cout << "BAD" << " " << result.first;
//     }
//     else {
//         cout << "GOOD";
//     }
//     return 0;
// }

bool is_divisible(const string& P, ll x) {
    ll remainder = 0;
    for (char c : P) {
        remainder = (remainder * 10 + (c - '0')) % x;
    }
    return remainder == 0;
}

int main() {
string P;
cin >> P;
ll K;
cin >> K;

for (ll i = 2; i < K; i++) {
    if (is_divisible(P, i)) {
        cout << "BAD " << i;
        return 0;
    }
}
cout << "GOOD";

}