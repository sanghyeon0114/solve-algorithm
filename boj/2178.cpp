#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<vector<int>> &distance, int x, int y, int N, int M) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for(int i = 0; i < 4; i++) {
        if(x+dx[i] < 0 || x+dx[i] > N || y+dy[i] < 0 || y+dy[i] > M) {
            continue;
        }
        if(graph[x+dx[i]][y+dy[i]] == 1) {
            if(distance[x+dx[i]][y+dy[i]] == 0 || distance[x+dx[i]][y+dy[i]] > distance[x][y] + 1) {
                distance[x+dx[i]][y+dy[i]] = distance[x][y] + 1;
                dfs(graph, distance, x+dx[i], y+dy[i], N, M);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(M));
    vector<vector<int>> distance(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < M; j++) {
            graph[i][j] = input.at(j) - '0';
        }
    }

    distance[0][0] = 1;
    dfs(graph, distance, 0, 0, N-1, M-1);

    cout << distance[N-1][M-1] << "\n";
    return 0;
}

/*
bfs로 풀어야 하는데, dfs로 풀었음.

하지만, bfs보다 dfs가 성능이 더 좋음.

dfs로 푸려면, 재귀&스택이 아니라 큐로 풀면 된다.

*/
