#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ans(n, -1);
    stack<int> s;
    for(int i = 0; i<n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i<n; i++) {
        while(!s.empty() && v[s.top()] < v[i]) {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    for(int i = 0; i<n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
