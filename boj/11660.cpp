#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <unordered_map>
#include <time.h>

using namespace std;

struct Position {
    int x1;
    int y1;
    int x2;
    int y2;
};

int main() {

    int N, M;
    cin >> N >> M;

    int arr[N][N] = {0, };
    int sum[N][N] = {0, };

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<Position> pos(M);

    for(int i = 0; i < M; i++) {
        cin >> pos[i].x1 >> pos[i].y1 >> pos[i].x2 >> pos[i].y2;
        pos[i].x1--;
        pos[i].y1--;
        pos[i].x2--;
        pos[i].y2--;
    }

    sum[0][0] = arr[0][0];
    for(int i = 1; i < N; i++) {
        sum[i][0] = sum[i-1][0] + arr[i][0];
        sum[0][i] = sum[0][i-1] + arr[0][i];
    }

    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            sum[i][j] = sum[i][j-1] + sum[i-1][j] + arr[i][j] - sum[i-1][j-1];
        }
    }


    for(int i = 0; i < M; i++) {
        int isPlus = 0;
        int result = sum[pos[i].x2][pos[i].y2];
        if(pos[i].y1 != 0) {
            result -= sum[pos[i].x2][pos[i].y1-1];
            isPlus++;
        }
        if(pos[i].x1 != 0) {
            result -= sum[pos[i].x1-1][pos[i].y2];
            isPlus++;
        }
        if(isPlus == 2) {
            result += sum[pos[i].x1-1][pos[i].y1-1];
        }
        cout << result << "\n";
    }

    return 0;
}

//x2 y2에다가 x2,y1-1 / x1-1, y2를 빼면 됨