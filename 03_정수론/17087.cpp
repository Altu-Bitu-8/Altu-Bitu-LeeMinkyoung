#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int gdcIter(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int getLargestD(vector<int> &location) {

    int d;
    int a, b, n, i;
    a = max(location[0], location[1]);
    b = min(location[0], location[1]);
    n = location.size() - 2;
    i = 2;
    d = gdcIter(a, b);
    while (n--) {
        a = max(d, location[i]);
        b = min(d, location[i]);
        d = gdcIter(a, b);
        i++;
    }

    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> kidLocation(n);

    if(n == 1) {
        cin >> kidLocation[0];
        cout << abs(kidLocation[0] - s);
    }
    else {
        for(int i = 0; i<n; i++) {
            int location = 0;
            cin >> location;
            kidLocation[i] = abs(s - location);
        }

        int d;
        d = getLargestD(kidLocation);

        cout << d;
    }
    return 0;
}
