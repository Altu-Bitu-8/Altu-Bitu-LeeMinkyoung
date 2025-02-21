#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void getClothes(unordered_map<string, int>& m, int n) {
    m.clear();
    for(int i = 0; i < n; i++) {
        string clothesName, clothesType;
        cin >> clothesName >> clothesType;
        m[clothesType]++;
    }

    int days = 1;

    for(const auto& clothesType : m)
    {
        days *= (clothesType.second + 1);
    }
    cout << days - 1 << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    for(int i = 0; i<t; i++) {
        cin >> n;
        unordered_map<string, int> m;
        getClothes(m, n);
    }
    return 0;
}
//-1 기억하기