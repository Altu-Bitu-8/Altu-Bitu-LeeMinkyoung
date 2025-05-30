#include <iostream>
#include <vector>
#include <queue>


using namespace std;

const int INF = 99999999;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dijkstra(const vector<vector<int>>& cave, int N) {
    vector<vector<int>> dist(N, vector<int>(N, INF));
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<>> pq;

    dist[0][0] = cave[0][0];
    pq.push({dist[0][0], {0, 0}});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        if (cost > dist[y][x]) continue;

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
                int newCost = cost + cave[ny][nx];
                if (newCost < dist[ny][nx]) {
                    dist[ny][nx] = newCost;
                    pq.push({newCost, {ny, nx}});
                }
            }
        }
    }

    return dist[N - 1][N - 1];
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int num = 1;
    while(true) {
        int ans;
        cin >> n;
        if(n == 0) {
            break;
        }
        vector<vector<int>> v(n, vector<int>(n));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                cin >> v[i][j];
            }
        }
        ans = dijkstra(v, n);
        cout << "Problem " << num << ": " << ans << "\n";
        num++;
    }

    return 0;
}
