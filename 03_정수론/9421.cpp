#include <iostream>
#include <vector>
#include <set>
using namespace std;
int squareRootSums(int n) {
    int ans = 0;
    int num = n;
    while (num > 0) {
        int digit;
        digit = num % 10;
        ans += digit*digit;
        num /= 10;
    }
    return ans;
}
void primeNumber(vector<bool> &v) {
    for(int i = 2; i<v.size(); i++) {
        if(v[i] == true) {
            for(int j = i*i; j<v.size(); j += i) {
                v[j] = false;
            }
        }
    }
}
void getHappyPrimeNumber(vector<bool> &v, int n) {
    set<int> s;
    if(v[n] == true) {
        int sqrt = n;
        while (sqrt != 1) {
            if(s.find(sqrt) != s.end()) {
                v[n] = false;
                return;
            }
            s.insert(sqrt);
            sqrt = squareRootSums(sqrt);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<bool> v(n+1, true);
    v[0] = v[1] = false;
    primeNumber(v);
    for(int i = 2; i<v.size(); i++) {
        getHappyPrimeNumber(v, i);
        if(v[i] == true) {
            cout << i << "\n";
        }
    }
    return 0;
}
