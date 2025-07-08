#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N, 0);
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    if(N == 1) {
        cout << arr[0] << "\n";
        return 0;
    }
    if(N == 2) {
        cout << arr[0]+arr[1] << "\n";
        return 0;
    }

    vector<int> dp(N, 0);
    dp[0] = arr[0];
    dp[1] = dp[0] + arr[1];
    dp[2] = max(arr[0] + arr[2], arr[1]+arr[2]);

    for(int i = 3; i < N; i++) {
        dp[i] = max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]);
    }

    cout << dp[N-1] << "\n";

    return 0;
}