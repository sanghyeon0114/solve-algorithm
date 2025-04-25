#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int dfs(int x, int y, vector<vector<int>> &map, int& result, int& height, int& width) {
    if(map[x][y] == 0) {
        return 0;
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    map[x][y] = 0;
    
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] >= 0 && x + dx[i] < height && y + dy[i] >= 0 && y + dy[i] < width && map[x + dx[i]][y + dy[i]] == 1) {
            dfs(x + dx[i], y + dy[i], map, result, height, width);
        }
    }
    return 1;
}

void testcase() {
    int height, width, count;
    cin >> height >> width >> count;
    vector<vector<int>> map(height, vector<int>(width, 0));

    for(int i = 0; i < count; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    int result = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(dfs(i, j, map, result, height, width)) {
                result++;
            }
        }
    }
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int T;
    cin >> T;
    //T = 1;
    for(int i = 0; i < T; i++) {
        testcase();
    }

    return 0;
}