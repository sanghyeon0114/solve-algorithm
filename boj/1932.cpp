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

int main() {

    int N;
    cin >> N;

    vector<vector<int>> arr(N, vector<int>(N, 0));
    vector<vector<int>> max(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    max[0][0] = arr[0][0];

    for(int i = 1; i <N; i++) {
        max[i][0] = max[i-1][0] + arr[i][0];
        for(int j = 1; j <= i; j++) {
            if(max[i-1][j] > max[i-1][j-1]) {
                 max[i][j] = max[i-1][j] + arr[i][j];
            } else {
                max[i][j] = max[i-1][j-1] + arr[i][j];
            }
        }
    }

    int max_num = max[N-1][0];
    for(int i = 1; i < N; i++) {
        if(max_num < max[N-1][i]) {
            max_num = max[N-1][i];
        }
    }

    cout << max_num << "\n";

    return 0;
}