#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    vector<int> cnt(100001, 0);
    int left = 0;
    int right = 0;
    while(right < n) {
        cnt[v[right]]++;
        while(cnt[v[right]] > k) {
            cnt[v[left]]--;
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }

    cout << ans;
    return 0;
}
