#include <iostream>
#include <vector>

using namespace std;

void generatePattern(int N) {
    vector<vector<char>> grid(N, vector<char>(N, '.'));

    for (int i = 0; i < N; i++) {
        int j = N - i - 1;
        if (i > j) continue;
        char color = (i % 2 == 0) ? '#' : '.';

        for (int x = i; x <= j; x++) {
            for (int y = i; y <= j; y++) {
                grid[x][y] = color;
            }
        }
    }

    for (const auto& row : grid) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    generatePattern(N);
    return 0;
}
