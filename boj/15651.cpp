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

void bt(int cur, int& maxNum, int pos, int& maxPos, int arr[]) {
    if(pos == maxPos) {
        arr[pos] = cur;
        for(int i = 1; i <= maxPos; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    } else if(cur > maxNum) {
        return;
    }
    if(cur != 0) {
        arr[pos] = cur;
    }

    for(int i = 1; i <= maxNum; i++) {
        if(i == 0) {
            continue;
        }
        bt(i, maxNum, pos+1, maxPos, arr);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    int arr[M+1] = {0, };
    bt(0, N, 0, M, arr);

    return 0;
} 