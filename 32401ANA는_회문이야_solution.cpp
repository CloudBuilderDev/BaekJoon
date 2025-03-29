#include <bits/stdc++.h>
using namespace std;



int main() {
    int N;
    string s;
    cin >> N;
    cin >> s;

    int count = 0;
    int firstA = 0;
    int Ntogle = 0;
    int secondA = 0;
    for(int i =0;i<s.length();i++) {
        if(s.at(i) == 'A' && !firstA) {
            firstA = 1;
        }
        if(s.at(i) == 'A' && !secondA && Ntogle){
            secondA = 1;
        }
        if(s.at(i) == 'N'){
            if(Ntogle) {
                firstA = 0;
                secondA = 0;
                Ntogle = 0;
            }else if(firstA){
                Ntogle = 1;
            }
        }
        if(firstA && Ntogle && secondA) {
            count++;
            Ntogle = 0;
            secondA = 0;
        }
    }
    cout << count;

    return 0;
}