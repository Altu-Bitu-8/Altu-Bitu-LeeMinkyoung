#include <iostream>
#include <string>
#include <vector>
using namespace std;

int burgerDistribution(vector<char> v, int k) {

    int ans = 0;
    int vector_size = v.size();
    for(int i = 0; i<vector_size; i++) {
        int temp = ans;
        if(v[i] == 'H' || v[i] == 'o') {
            continue;
        }
        for(int j = i-k; j<= i+k; j++) {
            if (j < 0 || j == i) {
                continue;
            }
            if(j>=vector_size) {
                break;
            }
            if (v[j] == 'H') {
                v[j] = 'o';
                ans++;
                break;
            }

        }

        if(temp > ans) {
            ans = temp;
        }
    }
    return ans;
}

int main() {
    //입력
    int n, k;
    cin >> n >> k;
    string s;
    vector<char> v(n);
    cin >> s;
    for(int i = 0; i<n; i++) {
        v[i] = s[i];
    }

    int ans = 0;

    //연산

    ans = burgerDistribution(v, k);

    //출력
    cout << ans;

    return 0;
}

// for(int i = 1; i <= k; i++) {
//     int temp = ans;
//         ans = 0;
//     for(int j = 0; j<v.size(); j++) {
//         if(v[j] == 'H') {
//             continue;
//         }
//         if(v[j] == 'P' && j >= i && v[j-i] == 'H') {
//             v[j-i] = 'o';
//             ans++;
//         }
//         else if(v[j] == 'P' && j >= i && v[j+i] == 'H') {
//             v[j+i] = 'o';
//             ans++;
//         }
//         else if(v[j] == 'P' && j < i && v[j+i] == 'H') {
//             v[j+i] == 'o';
//             ans++;
//         }
//     }
//
//     if(temp > ans) {
//         ans = temp;
//     }
// } 이렇게 했다가 예제 2는 답이 안나옴