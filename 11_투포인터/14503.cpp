// 14503: 로봇 청소기 (골드5/구현, 시뮬레이션)
#include <iostream>
#include <vector>

using namespace std;

const int CLEAN = 2; // 청소된 칸은 2로 표시

//방향 저장하는 배열
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; // 북 동 남 서

int clean(int n, int m, int r, int c, int d, vector<vector<int>> &board) {
    int cnt = 0; // 청소된 칸의 개수

    while(true) {
        // 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        if(board[r][c] != CLEAN) {
            cnt++; // 청소한 칸 ++
        }
        board[r][c] = CLEAN; // 청소 완료 상태로 표시

        bool find = false; // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는가
        for(int i = 0; i < 4; i++) {
            int nd = (d-i+3) % 4; //반시계 방향으로 회전한 새 방향
            int nr = r + dy[nd], nc = c + dx[nd];

            if(board[nr][nc] == 0) { // 3-2. 아직 청소되지 않은 빈 칸 발견
                find = true; // 주변에 청소할 칸 true
                r = nr; c = nc; d = nd; // 해당 방향으로 이동 및 회전
                break;
            }
        }
        if(find) { // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우 1번으로 돌아감
            continue;
        }

        // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        //후진 시도
        int bd = (d+2) % 4; // 현재 방향의 반대 방향
        int br = r + dy[bd], bc = c + dx[bd];

        // [바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가]
        // 2-2. 뒤쪽 칸이 벽이라 후진할 수 없는 경우
        if(board[br][bc] == 1) {
            return cnt; // 작동 멈추고 청소 개수 반환
        }
        // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진
        r = br; c = bc;
    }
    return cnt;
}

/*
 * [로봇 청소기 작동]
 * 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
 * 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
 *  2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
 *  2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
 * 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
 *  3-1. 반시계 방향으로 90º 회전한다.
 *  3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
 *  3-3. 1번으로 돌아간다.
*/

int main() {
    int n, m, r, c, d;
    vector<vector<int>> board;

    // 입력
    cin >> n >> m; // 방 크기 입력
    cin >> r >> c >> d; // 로봇 초기 위치와 방향
    board.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) { // 방 상태 입력
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 연산 & 출력
    cout << clean(n, m, r, c, d, board);
    
    return 0;
}