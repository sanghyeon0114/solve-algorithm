#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Position {
    int x;
    int y;
    int z;
    int day;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M, 0)));
    queue<Position> search;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) {
                    search.push({i, j, k, box[i][j][k]});
                }
            }
        }
    }

    while(!search.empty()) {
        Position pos = search.front(); search.pop();
        int dx[6] = {1, -1, 0, 0, 0, 0};
        int dy[6] = {0, 0, 1, -1, 0, 0};
        int dz[6] = {0, 0, 0, 0, 1, -1};

        for(int i = 0; i < 6; i++) {
            if(pos.x + dx[i] < 0 || pos.x + dx[i] >= H || pos.y + dy[i] < 0 || pos.y + dy[i] >= N || pos.z + dz[i] < 0 || pos.z + dz[i] >= M) {
                continue;
            }
            if(box[pos.x + dx[i]][pos.y + dy[i]][pos.z + dz[i]] == 0) {
                box[pos.x + dx[i]][pos.y + dy[i]][pos.z + dz[i]] = pos.day+1;
                search.push({pos.x + dx[i], pos.y + dy[i], pos.z + dz[i], box[pos.x + dx[i]][pos.y + dy[i]][pos.z + dz[i]]});
            }
        }
    }

    int maxCount = 0;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(box[i][j][k] == 0) {
                    cout << -1 << "\n";
                    return 0;
                }
                if(maxCount < box[i][j][k]) {
                    maxCount = box[i][j][k];
                }
            }
        }
    }

    cout << maxCount-1 << "\n";

    return 0;
}