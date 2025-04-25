#include <iostream>
#include <algorithm>
#include <vector>
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

    int arr[1000001] = {0, };

    for(int i = 2; i <= 1000000; i++) {
        arr[i] = arr[i-1]+1;

        if(i % 2 == 0) {
            arr[i] = min(arr[i], arr[i/2] + 1);
        }
        if(i % 3 == 0) {
            arr[i] = min(arr[i], arr[i/3] + 1);
        }
    }
    

    cout << arr[N] << "\n";
    return 0;
}