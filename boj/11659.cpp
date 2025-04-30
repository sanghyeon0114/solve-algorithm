#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;  
    cin >> N >> M;

    vector<int> arr(N, 0);
    vector<int> sum(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(i > 0) {
            sum[i] += arr[i] + sum[i-1];
        } else {
            sum[i] = arr[i];
        }
    }

    for(int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        if(start - 2 >= 0) {
            cout << sum[end-1] - sum[start-2] << "\n";
        } else {
            cout << sum[end-1] << "\n";
        }
    }

    return 0;
}