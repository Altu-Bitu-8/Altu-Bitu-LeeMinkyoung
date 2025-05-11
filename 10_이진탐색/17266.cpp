#include <iostream>
#include <vector>
using namespace std;

bool lightUp(vector<int> &x, int n, int mid) {
    int lastCover = 0;
    for(int i = 0; i<x.size(); i++) {
        int left = x[i] - mid;
        int right = x[i] + mid;

        if(left > lastCover) {
            return false;
        }
        lastCover = right;
    }
    return lastCover >= n;
}

int main() {

    int n, m;
    cin >> n;
    cin >> m;
    vector<int> x(m);
    for(int i = 0; i<m; i++) {
        cin >> x[i];
    }
    int min = 1;
    int max = n;
    int ans = n;
    while(min <= max) {
        int mid = (min + max)/2;
        if(lightUp(x, n, mid)) {
            ans = mid;
            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
