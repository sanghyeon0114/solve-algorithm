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

void bt(int cur, int& maxNum, int pos, int& maxPos, string str) {
    if(pos == maxPos) {
        str.append(to_string(cur));
        cout << str << "\n";
        return;
    } else if(cur >= maxNum) {
        return;
    }
    if(cur != 0) {
        str.append(to_string(cur));
        str.append(" ");
    }

    for(int i = cur+1; i <= maxNum; i++) {
        bt(i, maxNum, pos+1, maxPos, str);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    bt(0, N, 0, M, "");

    return 0;
} 