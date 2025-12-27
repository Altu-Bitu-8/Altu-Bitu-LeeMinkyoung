#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 101;
bool board[SIZE][SIZE];

int dx[4] = {1, 0, -1, 0}; // → ↑ ← ↓
int dy[4] = {0, -1, 0, 1};

void drawDragonCurve(int x, int y, int d, int g) {
    vector<int> dir;
    dir.push_back(d);


    for (int gen = 1; gen <= g; gen++) {
        int size = dir.size();
        for (int i = size - 1; i >= 0; i--) {
            dir.push_back((dir[i] + 1) % 4);
        }
    }

    board[y][x] = true;
    for (int i = 0; i < dir.size(); i++) {
        x += dx[dir[i]];
        y += dy[dir[i]];
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE)
            board[y][x] = true;
    }
}

int countSquares() {
    int cnt = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        drawDragonCurve(x, y, d, g);
    }

    cout << countSquares() << '\n';
    return 0;
}