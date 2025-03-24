// 연결요소의 개수 
#include<iostream>
#include <vector>

std::vector<int> vect[1001]; // 백터 객체 배열선언
int visited[1001];
int N, M;

void DFS(int vertex) {
    visited[vertex] = 1;
    for(int i =0; i< vect[vertex].size();i++) {
        if(!visited[vect[vertex][i]]) {
            DFS(vect[vertex][i]);
        }
    }
}

int main(){
    int v, u; 
    std::cin >> N >> M;
    int count = 0;

    for(int i=0;i<M;i++) {
        std::cin >> u >> v;
        vect[u].push_back(v);
        vect[v].push_back(u);
    }

   for(int i =1;i<=N; i++) {
    if(visited[i] == 0){
        count++;
        DFS(i);
    }
   }
   std::cout << count << "\n";
}

