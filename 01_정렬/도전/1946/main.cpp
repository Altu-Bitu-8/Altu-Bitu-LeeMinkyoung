#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

void appliedHumans(int n, vector<pair<int, int>>& arr) {
    arr.clear();
    for(int i = 0; i<n; i++) {
        int cv, interview;
        cin >> cv >> interview;
        arr.emplace_back(cv, interview);
    }
}
bool secondCompare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
int maxAcceptiance(vector<pair<int, int>>& arr) {

    int num = 0;
    sort(arr.begin(), arr.end());
    int maximum_1 = arr[0].second;
    for(int i = 0; i <arr.size(); i++) {
        if(arr[i].second <= maximum_1) {
            num++;
            maximum_1 = arr[i].second;
        }
    }


    return num;
}

int main() {
    int t, n;
    vector<pair<int, int>> v;
    cin >> t;
    for(int i = 0; i<t; i++) {
        cin >> n;
        appliedHumans(n, v);
        cout << maxAcceptiance(v) << "\n";
    }
    return 0;
}
