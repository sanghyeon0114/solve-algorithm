#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <iomanip> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    long long arr[N][2];

    for(int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    long long result = 0;

    for(int i = 0; i < N; i++) {
        result += arr[i%N][0] * arr[(i+1)%N][1];
        result -= arr[i%N][1] * arr[(i+1)%N][0];
    }
    
    result = abs(result);
    double result2 = (double)result/2.0;

    cout << fixed << setprecision(1) << round(result2 * 10) / 10 << "\n";

    return 0;
}
