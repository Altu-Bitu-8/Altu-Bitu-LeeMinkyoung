#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i<n+1; i++) {
        q.push(i);
    }
    while (q.size() != 1) {
        q.pop();
        int dummy;
        dummy = q.front();
        q.pop();
        q.push(dummy);
    }
    cout << q.front();
    return 0;
}
