#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<bool>> visited;

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int size = 1;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 상하좌우 방향 확인
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 범위를 벗어나는 경우 continue
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            // 방문하지 않았고, 1인 경우 큐에 넣기
            if (!visited[nx][ny] && graph[nx][ny] == 1) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                size++;
            }
        }
    }

    return size;
}

int main() {
    cin >> n >> m;

    graph.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int count = 0;  // 그림의 개수
    int max_size = 0;  // 가장 큰 그림의 넓이

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                count++;
                int size = bfs(i, j);
                max_size = max(max_size, size);
            }
        }
    }

    cout << count << endl;
    cout << max_size << endl;

    return 0;
}

