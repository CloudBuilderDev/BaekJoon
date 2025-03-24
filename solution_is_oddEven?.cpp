// 입력 받은 수열이 홀짝 수열인지 판별하는 알고리즘 O(n)
#include <iostream>
#include <string>
using namespace std;

int isOdd(int n) {
    return (n % 2) != 0 ? 1 : 0;
}
int isEven(int n) {
    return (n % 2) == 0 ? 1 : 0;
}

int main() {
    int n;
    int result = 1;
    cin >> n;
    
    int* arr = new int[n+1];
    for(int i=1; i<n+1; i++) {
        cin >> arr[i];
    }

    for(int i=1; i<n+1; i++) {
        // base
        if(i==1) result *= isOdd(arr[i]);
        if(i==2) result *= isEven(arr[i]);
        
        if(isOdd(i)) {
            if(isOdd(arr[i]) && arr[i-2] <= arr[i]) {
                result *= 1;
            }
            else result *= 0;
        }
        else {
            if(isEven(arr[i]) && arr[i-2] <= arr[i]) {
                result *= 1;
            }
            else result *= 0;
        }
    }
    cout << result;
    delete[] arr;
}