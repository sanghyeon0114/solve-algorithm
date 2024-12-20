#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    double max = 0;
    double sum = 0;

    double arr[N];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(max < arr[i]) {
            max = arr[i];
        }
    }

    for(int i = 0; i < N; i++) {
        sum += arr[i]/max;
    }

    cout << sum/N * 100.0 << endl;

    return 0;
}