#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K;
// vector<ll> squares;


// // 소수들의 제곱 수를 에라토네스의 체로 구하기 -> 잘 동작함 
// vector<ll> getPrime_squares(ll p) {
//     ll limit = sqrt(p); // 어떤 수 p 보다 작은 제곱수의 개수는 루트p 개 정도 보단 적겠지
//     vector<bool> is_prime(limit + 1, true);
//     vector<ll> prime_squares;

//     is_prime[0] = is_prime[1] = false;

//     for (ll i = 2; i <= limit; i++) {       
//         if (is_prime[i]) {
//             prime_squares.push_back(i * i);  // 소수의 제곱만 추가 굳이 다른 수들을 추가할 필요가 없음
//             for (ll j = i * i; j <= limit; j += i) { // i가 소수라면 i의 배수들은 소수가 아니니, p보다 작은 i의 배수들을 제거
//                 is_prime[j] = false;
//             }
//         }
//     }
//     return prime_squares;
// }
const int MAXN = 44721; // 루트 2*10^9 정도면 충분함 = 제곱 소수의 개수
int mobius[MAXN + 1];

void compute_mobius(int n) {
    vector<int> prime;
    vector<bool> is_prime(n + 1, true);
    mobius[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            mobius[i] = -1;
        }
        for (int p : prime) {
            if (i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) {
                mobius[i * p] = 0;
                break;
            } else {
                mobius[i * p] = mobius[i] * -1;
            }
        }
    }
}
ll square_free_count(ll p) {
    ll res = 0;
    for (ll i = 1; i * i <= p; i++) {
        res += mobius[i] * (p / (i * i));
    }
    return res;
}


// ll inclusion_exclusion(int idx, ll lcm_val, int parity, ll p, const vector<ll>& squares) {
//     if (lcm_val > p) return 0;

//     ll res = parity * (p / lcm_val);
//     for (int i = idx; i < squares.size(); i++) {
//         ll new_lcm = lcm_val * squares[i];
//         if (new_lcm > p) continue;
//         res += inclusion_exclusion(i + 1, new_lcm, -parity, p, squares);
//     }
//     return res;
// }

// ll count(ll p) {
//     return inclusion_exclusion(0, 1, 1, p, squares);
// }

// 비트마스킹으로 서브셋을 할 경우 반복문이 안 돌아갈 정도로 집합의 수가 많음.. 소수제곱수들의 수 만큼 2^소수제곱수개수 의 집합에 대한 연산을 해야함....
// ll count(ll p) {
//     auto squares = getPrime_squares(p);

//     ll count = 0;
//     int n = squares.size();
//     // 현재 p = 2030745 count가 0인상태
//     for (ll i = 1; i < (1 << n); i++) { // n = 224 인 경우 2^224인데... 너무 커서 그런가 반복문을 수행하지 않는다.
//         ll elements_lcm = 1;
//         ll elements = 0;

//         for (int j = 0; j < n; j++) {
//             if (i & (1 << j)) {
//                 elements++;
//                 elements_lcm = lcm(elements_lcm, squares[j]);
//             }
//         }

//         if (elements % 2 == 0)
//             count -= p / elements_lcm;
//         else
//             count += p / elements_lcm;
        
//     }

//     return p - count;
// }

ll searching(ll K) {
    ll left = 1;
    ll right = 2 * K;
    ll result = -1;

    while (left <= right) {
        ll mid = (left + right) / 2;

        if (square_free_count(mid) >= K) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    cin >> K;
    compute_mobius(MAXN);
    //squares = getPrime_squares(2*K);
    // for(ll i : squares) {
    //     cout << i << ' ';
    // }
    ll result = searching(K);
    cout << result;
    return 0;
}
