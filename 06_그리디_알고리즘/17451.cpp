#include <iostream>
#include <vector>
using namespace std;

long long parallel_space(vector<long long> &v, long long inital_speed, int n) {
    long long speed = inital_speed;
    for(int i = n; i >= 1; i--) {
        long long temp;
        temp = (speed/v[i]) *v[i];
        if(temp < speed) {
            speed = ((speed/v[i]) + 1)*v[i];
        }

    }

    return speed;
}

int main() {
    //입력
    int n;
    cin >> n;
    vector<long long> vi(n + 1);
    long long speed = 0;
    for(int i = 1; i <= n; i++) {
        cin >> vi[i];
    }
    speed = vi[n];

    //연산
    speed = parallel_space(vi, speed, n);

    //출력
    cout << speed;

    return 0;
}
