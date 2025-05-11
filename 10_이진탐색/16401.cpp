#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//조카 m명 대상으로 length 길이로 과자 나눠 줄 수 잇는지 확인
bool giveSnackOk(int length, int m, int n, vector<int> &v) {
    int count = 0; // 과자 개수
    for(int i = 0; i<n; i++) {
        count += v[i]/length;
    }
    return count >= m; //과자 개수가 조카 수 이상이면 true
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n; // 조카 수, 과자 수
    cin >> m >> n;
    int maxLength = 0; // 과자 중 최대 길이 저장
    vector<int> snack(n); // 과자 길이 저장
    for(int i = 0; i<n; i++) {
        cin >> snack[i];
        maxLength = max(maxLength, snack[i]); // 가장 긴 과자 찾아놓기
    }

    int min = 1; // 이진탐색
    int max = maxLength;
    int ans = 0;
    while(min <= max) {
        int mid = (min + max)/2; // 중간부터 시작
        if(giveSnackOk(mid, m, n, snack)) { // 현재 길이로 나눌 수 있다면
            ans = mid; // 답 저장하고
            min = mid + 1; // 더 길게도 가능한지 검색
        }
        else {
            max = mid - 1; // 아니면 길이 줄여서 다시
        }
    }
    cout << ans; // 답 출력
    return 0;
}
