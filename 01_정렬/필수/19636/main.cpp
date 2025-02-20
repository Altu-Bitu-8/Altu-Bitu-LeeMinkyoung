#include <iostream>
#include<cmath>
using namespace std;

void noChange(int w, int i0, int a, int i, int d) {

    for(int k = 0; k<d; k++) {
        w += (i - a - i0);
    }
    if(w <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << w << " " << i0 << "\n";
    }
}

void yesChange(int w, int i0, int a, int i, int d, int t) {

    int og;
    og = i0;
    for(int k = 0; k<d; k++) {
        int diet;
        diet = i -a - i0;
        w += diet;
        if(abs(diet) > t) {
            i0 += round((double)diet/2);
        }
        if(w <= 0) {
            cout << "Danger Diet\n";
        return;
        }
        else if (i0 <= 0) {
            cout << "Danger Diet\n";
        return;
        }
    }


    if(i0 < og) {
        cout << w << " "<< i0 << " YOYO\n";
    }
    else {
        cout << w << " " << i0 << " NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w0, i0, t;
    int d, i, a;

    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    noChange(w0, i0, a, i, d);
    yesChange(w0, i0, a, i, d, t);
    return 0;
}
