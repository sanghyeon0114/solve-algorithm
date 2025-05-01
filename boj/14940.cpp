#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

struct Position {
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M, 0));
    Position pos = {0, 0};

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                pos.x = i;
                pos.y = j;
            }
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    queue<Position> q;
    q.push(pos);

    vector<vector<int>> distance(N, vector<int>(M, -1));
    distance[pos.x][pos.y] = 0;

    while(!q.empty()) {
        Position cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            if(cur.x + dx[i] >= 0 && cur.x + dx[i] < N && cur.y + dy[i] >= 0 && cur.y + dy[i] < M && distance[cur.x+dx[i]][cur.y+dy[i]] == -1 && map[cur.x+dx[i]][cur.y+dy[i]] != 0) {
                distance[cur.x+dx[i]][cur.y+dy[i]] = distance[cur.x][cur.y] + 1;
                q.push({cur.x+dx[i], cur.y+dy[i]});
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0) {
                distance[i][j] = 0;
            }
            cout << distance[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

