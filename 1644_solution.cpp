#include <bits/stdc++.h>
using namespace std;

// 에라토네스의 체 N log logN
std::vector<int> getPrimes(int N) {
    std::vector<bool> is_prime(N + 1, true);
    std::vector<int> primes;
    
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

bool isPrime(int n) {  // 루트 N보다 살짝 더 작음
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {  // 6k ± 1만 검사
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int N; cin >> N;
    vector<int> primes;
    int sum;
    int p = 0;int q = 1;
    if (N != 1) {
         primes = getPrimes(N);
         sum = primes[p] + primes[q];
        }

    int count = 0;
    while(1) {
        if(N==1 || N==2 || N==3) break;
        if(sum < N){
            q++;
            sum += primes[q];
        }
        else if(sum > N) {
            sum -= primes[p];
            p++;
        }
        else {
            count++;
            sum -= primes[p];
            p++;
        }
        //if((q-p==1) && (primes[p]+primes[q] > N)) break;
        if(p==q || q == primes.size()) break;
    }
    if(isPrime(N)) count++;
    cout << count;
    return 0;
}















