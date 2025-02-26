#include <iostream>
#include<string>
#include<vector>
#include <set>

using namespace std;

void substring(set<string>& set, int size, string s) {
    for(int i = 0; i<size; i++) {
        for(int k = 0; k<size; k++) {
            set.insert(s.substr(i,k));
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string S;
    cin >> S;

    //vector<string> v;
    set<string> s;
    substring(s, S.size(), S);
    /*sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    이렇게 짜도 답은 나오지만 시간초과가... 나온다...
    ++ 벡터를 그냥 사용 안하는게 낫다. 메모리 초과가 나온다.
    */


    cout << s.size();

    return 0;
}
