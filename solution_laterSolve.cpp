#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M;
    
vector<vector<int>> board(N, vector<int>(M));

void printboard(std::vector<std::vector<int>>& board, int N, int M){
    for(int i = 0; i< N;i++){
        for(int j = 0; j<M ; j++){
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}
int range(int i, int j, vector<vector<int>>& board){
    int N = board.size();
    int M = board[0].size();
    if ((0 < i && i < N) && (0 < j && j < M)) {
        return 1;
    }else {
        return 0;
    } 
}

int BFS(int i, int j, vector<vector<int>>& board) {
    int N = board.size();
    int M = board[0].size();
    int depth = 0;
    depth++;
    if((i == N-1) && (j == M-1)) return depth;

    if(board[i][j+1] && range(i,j+1,board)){
        BFS(i,j+1,board); // 오른쪽
    }
    else if(board[i+1][j] && range(i+1,j,board)){ // 아래
        BFS(i+1,j,board);
    }
    else if(board[i-1][j] && range(i-1,j,board)){ // 위
        BFS(i-1,j,board);
    }
    else if(board[i][j-1] && range(i,j-1,board)){ // 왼쪽
        BFS(i,j-1,board);
    }
    else{
        cout << "Fuck" << endl;
    }
    
    return 0;
}

int main() {
    cin >> N >> M;
   
    for(int i =0; i<N;i++){
        string s;
        cin >> s;
        for(int j = 0; j<M; j++) {
            board[i].push_back(s.at(j) -'0');
        }
    }
    //printboard(board, N, M);
   cout << BFS(0,0,board);
}

