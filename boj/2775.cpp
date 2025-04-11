#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int k, n;
        cin >> k >> n;

        vector<vector<int>> arr(k+1, vector<int>(n+1, 0));

        for(int i = 0; i <= n; i++) {
            arr[0][i] = i;
        }
        for(int i = 0; i <= k; i++) {
            arr[k][0] = 0;
        }

        for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= n; j++) {
                arr[i][j] = arr[i][j-1] + arr[i-1][j];
            }
        }

        cout << arr[k][n] << endl;
    }
    
    return 0;
}