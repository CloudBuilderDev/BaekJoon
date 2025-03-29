#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, S = 0;
    cin >> M;

    while (M--) {
        string cmd;
        int x; // 1 <= x <= 20

        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            S |= (1 << (x - 1));
        }
        else if (cmd == "remove") {
            cin >> x;
            S &= ~(1 << (x - 1));
        } 
        else if (cmd == "check") {
            cin >> x;
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << "\n";
        } 
        else if (cmd == "toggle") {
            cin >> x;
            S ^= (1 << (x - 1));
        } 
        else if (cmd == "all") {
            S = (1 << 20) - 1;  
        } 
        else if (cmd == "empty") {
            S = 0; 
        }
    }

    return 0;
}
