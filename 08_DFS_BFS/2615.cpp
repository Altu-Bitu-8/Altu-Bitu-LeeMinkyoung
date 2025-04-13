#include <iostream>
#include <vector>

using namespace std;
pair<int, int> ii = {0, 0};

void check(int n, vector<vector<int>> &gomoku, int i, int j) {
    int row[4] = {0, 1, 1, -1};
    int col[4] = {1, 0, 1, 1};

    for (int d = 0; d < 4; d++) {
        int cnt = 1;
        int r = i;
        int c = j;

        int prevR = r - row[d];
        int prevC = c - col[d];
        if (prevR >= 0 && prevC >= 0 && prevR < 19 && prevC < 19 && gomoku[prevR][prevC] == n) {
            continue;
        }
        while (true) {
            int nr = r + row[d];
            int nc = c + col[d];

            if (nr < 0 || nc < 0 || nr >= 19 || nc >= 19) break;
            if (gomoku[nr][nc] != n) break;

            cnt++;
            r = nr;
            c = nc;

        }
        int nextR = r+row[d];
        int nextC = c + col[d];
        if(cnt == 5 && (nextR >= 0 && nextC >= 0 && nextR < 19 && nextC < 19 && gomoku[nextR][nextC] == n)) {
            continue;
        }
        if (cnt == 5 && ii.first == 0) {
            ii.first = i + 1;
            ii.second = j + 1;
            return;
        }
    }
}

void winGomoku(vector<vector<int>> &gomoku) {
    for(int i = 0; i<19; i++) {
        for(int j = 0; j<19; j++) {
            if(gomoku[i][j] != 0) {
                check(gomoku[i][j], gomoku, i, j);
                if(ii.first != 0) return;
            }

        }
    }
}

int main() {

    vector<vector<int>> gomoku(19, vector<int>(19));

    for(int i = 0; i<19; i++) {
        for(int j = 0; j<19; j++ ) {
            int num;
            cin >> num;
            gomoku[i][j] = num;
        }
    }

    winGomoku(gomoku);
    int win;
    if(ii.first == 0) {
        cout << 0;
    }
    else {
        win = gomoku[ii.first-1][ii.second-1];
        cout << win << endl;
        cout << ii.first << " " << ii.second;
    }

    return 0;
}
