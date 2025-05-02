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

int C[1001][1001] = {0, };

int combination(int n, int r)
{
    if(C[n][r]) {
        return C[n][r];
    }
    if(n == r || r == 0) {
        C[n][r] = 1;
        return 1; 
    } else {
        int first = 0;
        int second = 0;
        if(C[n-1][r-1]) {
            first = C[n-1][r-1];
        } else {
            first = combination(n - 1, r - 1);
        }
        if(C[n-1][r]) {
            second = C[n-1][r];
        } else {
            second = combination(n - 1, r);
        }
        C[n][r] = (first+second) % 10007;
        return first+second;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N, 0);
;
    int two = N/2;
    int count = 0;

    for(int i = 0; i <= two; i++) {
        count += combination(N-i, i);
        count %= 10007;
    }

    cout << count << "\n";

    return 0;
}