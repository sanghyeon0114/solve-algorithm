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

void printStar(vector<vector<bool>> &arr, int N, int x, int y) {
    if(N == 3) {
        arr[x][y+2] = arr[x+1][y+1] = arr[x+1][y+3] = arr[x+2][y] = arr[x+2][y+1] = arr[x+2][y+2] = arr[x+2][y+3] = arr[x+2][y+4] = 1;
        return;
    }
    int div = N/2;
    printStar(arr, div, x, y+div);
    printStar(arr, div, x+div, y);
    printStar(arr, div, x+div, y+N);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<bool>> arr(N, vector<bool>(N*2-1, 0));
    printStar(arr, N, 0, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N*2-1; j++) {
            cout << (arr[i][j] ? "*" : " ");
        }
        cout << "\n";
    }

    return 0;
}