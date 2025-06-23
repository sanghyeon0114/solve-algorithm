#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();

    int value[N+1][3] = {0, };

    for(int i = 1; i <= N; i++) {
        cin >> value[i][0] >> value[i][1] >> value[i][2];
    }

    int RGB[N+1][3] = {0, };

    for(int i = 1; i <= N; i++) {
        RGB[i][0] = min(RGB[i-1][1], RGB[i-1][2]) + value[i][0];
        RGB[i][1] = min(RGB[i-1][0], RGB[i-1][2]) + value[i][1];
        RGB[i][2] = min(RGB[i-1][1], RGB[i-1][0]) + value[i][2];
    }

    cout << min(min(RGB[N][0], RGB[N][1]), RGB[N][2]) << "\n";

    return 0;
} 