#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

int dfs(int num, vector<bool> &worm, vector<vector<int>> &cc) {


    worm[num] = true;
    for(int k : cc[num]) {
        if(!worm[k]) {
            ans++;
            dfs(k, worm, cc);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int connected;
    cin >> n;
    cin >> connected;
    vector<vector<int>> connectedComputers(n+1);
    vector<bool> worm(n+1, false);
    for(int i = 0; i<connected; i++) {

        int j, k;
        cin >> j >> k;
        connectedComputers[j].push_back(k);
        connectedComputers[k].push_back(j);
    }
    cout << dfs(1, worm, connectedComputers);
    return 0;
}
