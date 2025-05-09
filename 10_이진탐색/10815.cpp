#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int haveCard(vector<int> &have, vector<int> &check, int num, int n) {
    int min = 0;
    int max = n - 1;
    while(min <= max) {
        int mid = (min + max)/2;
        if(check[num] == have[mid]) {
            return 1;
        }
        else if(check[num] > have[mid]) {
            min = mid + 1;
        }
        else if(check[num] < have[mid]) {
            max = mid - 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> have(n);
    for(int i = 0; i<n; i++) {
        cin >> have[i];
    }
    sort(have.begin(), have.end());
    int m;
    cin >> m;
    vector<int> check(m);
    for(int i = 0; i<m; i++) {
        cin >> check[i];
    }
    for(int i = 0; i<m; i++) {
        cout << haveCard(have, check, i, n) << " ";
    }


    return 0;
}
