#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string A, B;
    cin >> A >> B;
    int maxLength = max(A.length(), B.length());
    A = string(maxLength-A.length(), '0') + A;
    B = string(maxLength-B.length(), '0') + B;

    string C;
    int carry = 0;
    for(ll i = maxLength-1; i>=0; i--) {
        int tmp = (A[i]-'0') + (B[i]-'0') +carry;
        carry = tmp/10;
        C += (tmp % 10) + '0';
    }
    if (carry > 0) {
        C += (carry + '0');
    }
    reverse(C.begin(), C.end());
    cout << C;
    return 0;
}

