#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countDiffType(vector<int> &v, int c, int i, int k, int n, int d) {
    int ans = 0;
    int num = 0;
    vector<bool> type(d + 1, false);
    for(int j = 0; j<k; j++) {
        num = j + i;
        if(num >= n) {
            num -= n;
        }
        type[v[num]] = true;
    }

    type[c] = true;

    for(int p = 0; p<d + 1; p++) {
        if(type[p] == true) {
            ans++;
        }
    }
    return ans;

}

int main() {

    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 0; i<n; i++) {
        ans = max(ans, countDiffType(v, c, i, k, n, d));
    }
    cout << ans;
    return 0;
}
