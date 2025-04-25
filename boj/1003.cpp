#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int fibo[41][2] = {0, };

void fibonacci(int n, int (&arr)[]) {
    if(n == 0) { 
        arr[0]++;
    } else if(n == 1) {
        arr[1]++;
    } else {
        if(fibo[n-1][0] == 0 && fibo[n-1][1] == 0) {
            fibonacci(n-1, arr);
        } else {
            arr[0] += fibo[n-1][0];
            arr[1] += fibo[n-1][1];
        }
        if(fibo[n-2][0] == 0 && fibo[n-2][1] == 0) {
            fibonacci(n-2, arr);
        } else {
            arr[0] += fibo[n-2][0];
            arr[1] += fibo[n-2][1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i <= 40; i++) {
        int arr[2] = {0, 0};
        fibonacci(i, arr);
        fibo[i][0] = arr[0];
        fibo[i][1] = arr[1];
    }

    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << fibo[N][0] << " " << fibo[N][1] << "\n";
    }

    return 0;
}