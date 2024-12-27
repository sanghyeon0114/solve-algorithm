#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    int result = 1;

    for(int i = N-K+1; i <= N; i++) {
        result *= i;
    }

    for(int i = 1; i <= K; i++) {
        result /= i;
    }

    cout << result << "\n";

    return 0;
}