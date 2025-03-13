#include <iostream>

using namespace std;

int ESM(int e, int s, int m) {
    int year = 1;
    int E, S, M;
    E = S = M = 1;
    while ((E != e) || (S != s) || (M != m)) {//받은 변수와 처음 카운트 할 변수가 전부 같아질때까지
        E++;
        S++;
        M++;
        year++;
        if(E>15) {
            E = 1;
        }
        if(S>28) {
            S = 1;
        }
        if(M>19) {
            M = 1;
        }
    }
    return year;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입력
    int e, s, m;
    cin >> e >> s >> m;

    //연산
    int year = ESM(e, s, m);

    //출력
    cout << year;
    return 0;
}
