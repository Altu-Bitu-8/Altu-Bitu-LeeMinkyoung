#include <iostream>
#include <vector>
#include<string>
#include <cmath>
using namespace std;

typedef pair<int, int> ii;

void turnCogwheel(int direction, vector<vector<int>> &v, int num) {
    switch (direction) {

        case 1:
            v[num].insert(v[num].begin(), v[num].back());
            v[num].pop_back();
            break;
        case -1:
            v[num].push_back(v[num].front());
            v[num].erase(v[num].begin());
            break;
    }
}

void saveCogwheel(vector<vector<int>> &v, vector<ii> &turn, int k, int t) {
    for(int i = 0; i<k; i++) {
        int num = turn[i].first;
        vector<int> save(t, 0);
        save[num] = turn[i].second;
        for (int j = num - 1; j>=0; j--) {
            if(v[j][2] != v[j+1][6]) {
                save[j] = -save[j+1];
            }
            else {
                break;
            }
        }
        for(int j = num + 1; j<t; j++) {
            if(v[j][6] != v[j-1][2]) {
                save[j] = -save[j-1];
            }
            else {
                break;
            }
        }
        for(int j = 0; j<t; j++) {
            if(save[j] != 0) {
                turnCogwheel(save[j], v, j);
            }
        }


    }
}
//12시 방향(0번째 인덱스)가 1인 벡터의 개수 세기
int itsOneAtTwelfth(vector<vector<int>> &v, int t) {
    int ans = 0;
    for(int i = 0; i<t; i++) {
        if(v[i][0] == 1) {
            ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int t;
    cin >> t;
    vector<vector<int>> v(t, vector<int>(8));
    for(int i = 0; i<t; i++) {
        string s;
        cin >> s;
        for(int j = 0; j<8; j++) {
            v[i][j] = s[j] - '0';
        }
    }

    int k;
    cin >> k;
    vector<ii> turn(k);
    for(int i = 0; i<k; i++) {
        cin >> turn[i].first >> turn[i].second;
        turn[i].first--;
    }

    //연산
    saveCogwheel(v, turn, k, t);
    int ans = itsOneAtTwelfth(v, t);

    //출력
    cout << ans;


    return 0;
}
