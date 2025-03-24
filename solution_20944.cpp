#include <iostream>
#include <string>
using namespace std;


int pelindrom(int n, char* arr){
    int i;
    int j;

    if(n%2 == 0){
        i = n/2;
        j = i+1;
    } else{
        i = n/2 -1;
        j = n/2 +1;
    }
    for(int k=0; k< n/2; k++){
        if(arr[i++] != arr[j++]) return 0;
    }
    return 1;
}

int sumisang(int n, char* arr){
    int i = 0;
    int j;

    if(n%2 == 0){
        j = n/2;
    } else{
        j = n/2 +1;
    }
    for(int k=0; k< n/2; k++){
        if(arr[i++] != arr[j++]) return 0;
    }
    return 1;
}


int main(){
    int n;
    cin >> n ;
    int c = 'a';
    int last = 'z';
    char* arr = new char[n];
    for(;c< last; c++){
        for(int i=0;i<n;i++){
            arr[i] = c;
        }
        if(pelindrom(n, arr) && sumisang(n, arr)) {
            cout << arr;
        }
    }
}
/* 그냥 얼탱이가 없네...
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << 'a';
    }
    cout << endl;

    return 0;
}

*/