#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

long cutting(long (&arr)[], int N, int value) {
    long result = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i] > value) {
            result += arr[i] - value;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    long arr[N];

    long begin = 0, end = 0;
    long mid = 0;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(end < arr[i]) {
            end = arr[i];
        }
    }
    mid = (begin + end)/2;
    
    
    long cut;
    long max;

    while(begin <= end) {
        cut = cutting(arr, N, mid);
        if(cut < M) {
            end = mid-1;
        } else {
            if(max < mid) {
                max = mid;
            }
            begin = mid+1;
        }
        mid = (begin + end)/2;
    }

    cout << mid << "\n";

    return 0;
}

