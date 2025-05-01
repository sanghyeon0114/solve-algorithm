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

void findCC(vector<vector<bool>> &arr, bool (&isVisited)[], int current, int N) {
    for(int i = 1; i <= N; i++) {
        if(arr[current][i] && !isVisited[i]) {
            isVisited[i] = true;
            findCC(arr, isVisited, i, N);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> arr(N+1, vector<bool>(N+1, false));

    int x, y;
    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        arr[x][y] = arr[y][x] = true;
    }

    bool isVisited[N+1] = {false, };
    int count = 0;

    for(int i = 1; i <= N; i++) {
        if(!isVisited[i]) {
            findCC(arr, isVisited, i, N);
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}