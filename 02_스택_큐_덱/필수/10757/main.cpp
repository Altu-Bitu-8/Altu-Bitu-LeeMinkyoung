#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

void getNumbers(deque<int>& d, string str) {

    for(int i = 0; i<str.size(); i++) {
        int n = str[i] - '0';
        d.push_back(n);
    }
}
int main() {
    deque<int> a, b;
    string aStr, bStr;
    cin >> aStr >> bStr;
    getNumbers(a, aStr);
    getNumbers(b, bStr);
    int largerSize = max(a.size(), b.size());
    while (a.size() < largerSize) {
        a.push_front(0);
    }
    while (b.size() < largerSize) {
        b.push_front(0);
    }

    vector<int> v;
    int overTen = 0;
    for(int i = 0; i < largerSize; i++) {
        int sum = a.back() + b.back() + overTen;
        v.push_back(sum%10);
        overTen = sum/10;
        a.pop_back();
        b.pop_back();
    }
    if(overTen > 0) {
        v.push_back(overTen);

    }
    for(int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
    }
    cout << "\n";
    return 0;
}
