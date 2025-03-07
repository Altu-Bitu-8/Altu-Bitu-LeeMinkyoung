#include <iostream>
#include <vector>
#include <set>

using namespace std;

void wheelOfFortune(vector<char> &v, int iter) {
    int size = v.size();
    for(int p = 0; p<v.size(); p++) {
        cout << v[iter];
        iter = (iter - 1 + size)%size;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<char> v(n, '?');
    set<char> s;
    int iter = 0;
    int i;
    char c;
    bool isExist = true;
    while(k--) {
        cin >> i >> c;
        iter = (iter + i)%n;
        if(v[iter] == '?') {
            if(s.find(c) != s.end()) {
                isExist = false;
            }
            v[iter] = c;
            s.insert(c);
        }
        else if (v[iter] == c) {
            continue;
        }
        else {
            isExist = false;
        }
    }
    if(isExist == false) {
        cout << "!";
    }
    else {
        wheelOfFortune(v, iter);
    }
    return 0;
}
