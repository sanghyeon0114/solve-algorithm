#include <iostream>
#include <vector>

using namespace std;

int removeOnePicture(vector<vector<int>> &graph, int x, int y, int maxX, int maxY) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int size = 0;

    if(graph[x][y] == 1) {
        size++;
        graph[x][y] = 0;
    }

    for(int i = 0; i < 4; i++) {
        if(x+dx[i] < 0 || x+dx[i] >= maxX || y+dy[i] < 0 || y+dy[i] >= maxY) {
            continue;
        }
        if(graph[x+dx[i]][y+dy[i]] == 1) {
            size += removeOnePicture(graph, x+dx[i], y+dy[i], maxX, maxY);
        }
    }

    return size;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int maxSize = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == 0) {
                continue;
            }
            int tmpSize = removeOnePicture(graph, i, j, n, m);
            if(tmpSize == 0) {
                continue;
            }
            count++;
            if(maxSize < tmpSize) {
                maxSize = tmpSize;
            }
        }
    }

    cout << count << "\n";
    cout << maxSize << "\n";

    return 0;
}

/*
1 1
1
1
1


3 3
1 0 1
0 1 0
1 0 1
5
1


6 5
1 1 0 1 1
0 1 1 0 0
0 0 0 0 0
1 0 1 1 1
0 0 1 1 1
0 0 1 1 1
4
9
*/