#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printBoard(vector<vector<int>>& board) {
    int N = board.size();
    for(int i =1;i<= N;i++){
        for(int j=1;j<=N;j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int N, I, M;
    cin >> N >> I >> M;
    vector<vector<int>> board(N+1, vector<int>(N+1));
    for(int i =1;i<=M;i++){
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    printBoard(board);
    return 0;
}