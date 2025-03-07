#include <iostream>
#include <vector>

using namespace std;

const int MAX_NUM = 1000000;
   void isPrime(vector<bool> &v) {
    v[0] = v[1] = false;
    for(int i = 2; i*i <= MAX_NUM; i++) {
        if(v[i] == true) {
            for(int k = i*i; k<= MAX_NUM; k += i) {
                v[k] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> is_prime(MAX_NUM + 1, true);
    isPrime(is_prime);

    int n;
    cin >> n;
    while(n) {
        int a, b;
        a = -1;
        for(int i = 3; i <= (n/2); i += 2) {
            if(is_prime[i] && is_prime[n-i]) {
                a = i;
                b = n - a;
                cout << n << " = " << a << " + " << b << "\n";
                break;
            }
            else if ((is_prime[i] == true) && (is_prime[n-i] == false)) {
                continue;
            }
        }
        if(a == -1) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
        cin >> n;
    }
    return 0;
}
