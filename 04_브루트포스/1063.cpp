#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<char, char> cc; // 체스판에 사용할 페어를 미리 타입 데프 해놔서 쉽게 사용하도록 함


//input에 따라 x와 y를 이동시킨다.

cc move(string input, char x, char y) {
    for (char how : input) { //입력된 문자열을 한 문자씩 확인
        if (how == 'R') { // 오른쪽으로 이동하면 x에 1을 더해준다
            x++;
        } else if (how == 'L') { // 왼쪽으로 이동하면 x에 -1을 해준다
            x--;
        } else if (how == 'B') { // 아래로 이동하면 y를 빼줌
            y--;
        } else {  // (how == 'T')
            y++; // 위로 이동하면 y를 더해줌
        }
    }
    return {x, y}; // 바뀐 위치 반환
}

/**
 * 두 좌표의 위치가 일치하는지 확인한다.
*/
bool isSame(cc k, cc s) {
    return (k.first == s.first && k.second == s.second);
}

/**
 * 체스판 범위를 넘어서는지 확인한다.
*/
bool checkRange (cc pos) {
    if (pos.first < 'A' || pos.first > 'H' || pos.second < '1' || pos.second > '8') {
        return false; // 체스판 벗어나면 false
    }
    return true; // 안 벗어나면 true
}

int main() {
    cc k, s;  // king, stone 위치 & 위에서 정의한 페어 타입으로 변수 생성
    int n; // 받는 입력 개수
    string input; // 이동 명령 받는 변수 & rt와 같이 두글자도 있기에 String으로 받아야함

    // 입력 (킹 처음 위치 / 돌 처음 위치 / 이동 횟수
    cin >> k.first >> k.second >> s.first >> s.second >> n;

    // 연산
    while (n--) {//n번 동안
        cin >> input; // 이동 명령 받음

        cc next_k, next_s; // 킹과 돌의 다음 위치

        // king 이동
        next_k = move(input, k.first, k.second);

        // stone 이동
        if (isSame(next_k, s)) {  // 이동한 king과 stone 위치가 일치하면
            // king이 움직인 방향과 같은 방향으로 이동
            next_s = move(input, s.first, s.second); //돌도 킹이랑 같은 방향으로 이동
        }
        else {
            next_s = s; // 킹과 돌의 위치가 일치 안하면 유지
        }

        // 체스판 밖으로 나가지 않을 경우만 이동
        if (checkRange(next_k) && checkRange(next_s)) {
            k = next_k; //킹 위치 갱신
            s = next_s; // 돌 위치 갱신
        }
    }

    // 출력
    cout << k.first << k.second << '\n' << s.first << s.second;

    return 0;
}