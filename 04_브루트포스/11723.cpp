#include <iostream>
#include <string>
using namespace std;

void bitmasking_set(string s, int x, int &n) {
    if(s == "add") {
        n |= 1 << x;
    }
    else if(s == "remove") {
        n &= ~(1 << x);
    }
    else if(s == "check") {
        int temp = (n & (1 << x)) ? 1:0; //이런 형식의 문법에 익숙하지 않아서 이거 찾는데 시간이 좀 걸렸다. 익숙해지길...
        cout << temp << "\n";
    }
    else if(s == "toggle") {
        n ^= (1<<x);
    }
    else if(s == "all") {
        n = (1 << 21) - 2;
    }
    else if(s == "empty"){
        n = 0;
    }
}

void get_order(int m, int &n) {
    string s;
    int x;
    for(int i = 0; i<m; i++) {
        cin >> s;
        if((s == "all") || (s == "empty")) {
            x = 0;
        }
        else {
            cin >> x;
        }
        bitmasking_set(s, x, n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int m;
    cin >> m;
    int n = 0;

    //연산 & 출력
    get_order(m, n);
    return 0;
}
//비트마스킹이 아닌 그냥 set을 이용해 풀었다가 시간 초과가 나왔다.