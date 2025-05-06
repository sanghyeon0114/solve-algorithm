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

int N;

bool checkBoard(vector<int> &arr, int x, int y) {
    for(int i = 0; i < x; i++) {
        if( arr[i] == -1) {
            continue;
        }
        if(arr[i] == arr[x] || abs(i-x) == abs(arr[i]-arr[x])) {
            return false;
        }
    }
    return true;
}

void bt(vector<int> &arr, int x, int& count) {
    if(x == N) {
        count++;
        return;
    }
    for(int i = 0; i < N; i++) {
        arr[x] = i;
        if(checkBoard(arr, x, arr[x])) {
            bt(arr, x+1, count);
        }
    }
    arr[x] = -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    cin >> N;
    vector<int> arr(N, -1);

    int count = 0;
    bt(arr, 0, count);

    cout << count << "\n";

    return 0;
} 