#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestIncreasingSequence(const vector<int> v, int a) {
    vector<int> dp(a, 1);

    for(int i = 1; i<a; i++) {
        for(int j = 0; j<i; j++) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}


int main() {
    //입력
    int a;
    cin >> a;
    vector<int> v(a);
   // vector<int> copy(a);
    for(int i = 0; i<a; i++) {
        cin >> v[i];
        //copy[i] = v[i];
    }
    // int least, most;
    // sort(copy.begin(), copy.end());
    // least = copy[0];
    // most = copy[a-1];

    int ans = largestIncreasingSequence(v, a);

    cout << ans;
    return 0;
}
