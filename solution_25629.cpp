// 홀짝 수열을 만들 수 있는지 판별
#include <iostream>
#include <string>
using namespace std;
int isOdd(int n) {
    return (n % 2) != 0 ? 1 : 0;
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    int input;
    for(int i=0; i<n; i++) {
        cin >> input;
        if(isOdd(input)) count++;
    }
    if(isOdd(n)) {
        cout << (count == (n/2+1) ? 1 : 0);
    }
    else {
        cout << (count == (n/2) ? 1 : 0);
    }
}