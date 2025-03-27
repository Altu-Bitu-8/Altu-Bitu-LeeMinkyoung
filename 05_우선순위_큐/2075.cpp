#include <iostream>
#include <queue>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입력
    int n;
    cin >> n;
    int N = n*n;
    priority_queue<int, vector<int>, greater<int>> pq;

    //연산
    for(int i = 0; i<N; i++) {
        int num;
        cin >> num;
        pq.push(num);
        if(pq.size() > n) {
            pq.pop();
        }
    }
    //출력

    cout << pq.top();

    return 0;
}
