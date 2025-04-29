#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

struct Position {
    int x;
    int y;
    int day;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int M, N;
    cin >> M >> N;

    int arr[N][M];

    queue<Position> q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                q.push({i, j, 0});
            }
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int max_day = 0;

    while(!q.empty()) {
        Position pos = q.front(); q.pop();
        if(max_day < pos.day) {
            max_day = pos.day;
        }
        for(int i = 0; i < 4; i++) {
            if(pos.x+dx[i] >= 0 && pos.x+dx[i] < N && pos.y+dy[i] >= 0 && pos.y+dy[i] < M) {
                if(arr[pos.x+dx[i]][pos.y+dy[i]] == 0) {
                    q.push({pos.x+dx[i], pos.y+dy[i], pos.day+1});
                    arr[pos.x+dx[i]][pos.y+dy[i]] = 1;
                }
            }
        }
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == 0) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << max_day << "\n";
    
    return 0;
}

