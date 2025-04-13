#include<iostream>

using namespace std;

int graph[101][101] = {0,}; // 그래프
int visited[101] = {false, }; // 방문 여부
int p1, p2; // 촌수를 계산해야하는 서로 다른 두 사람의 번호

int n; //전체 사람의 수
int m; // 부모 자식들 간의 관계의 개수


int dfs(int from) {//dfs 함수: 현재 사람 from부터 시작해서 p2까지 촌수 계산해줌

    int ret = -1; // 경로가 없는 기본값은 -1

    if (graph[from][p2] == 1) {//바로 연결되어 있으면 촌수 1
        return 1;
    }

    else {// 촌수가 1이 아니면 모든 사람들을 탐색하면서 연결되어 있으면 호출
        for (int i = 1; i <= n; ++i) {
            if (i == from) {
                continue; // 자기를 참조할 때는 건너뜀
            }
            if (graph[from][i] == 1 && !visited[i]) { // 사람이 연결 되어있고, 참조하지 않은 사람이라면 dfs 함수 호출
                visited[i] = true; // 방문한거 표시
                ret = max(ret, dfs(i)); //여러 경로가 있을 경우 가장 큰 값 저장
            }
        }
    }

    if (ret != -1) {//경로를 찾으면 촌수 하나 증가
        ret += 1;
    }
    return ret; //촌수 리턴

}

int main() {
    cin >> n; //사람 수
    cin >> p1 >> p2; //촌수 계산할 사람
    cin >> m; // 관계 개수

    for (int i = 0; i < m; ++i) { // 부모 자식간의 관계의 개수 m 개 입력
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1; // 무방향 그래프로 저장
    }

    int ans = dfs(p1); // dfs 함수 호출
    cout << ans;
}