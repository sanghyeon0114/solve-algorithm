#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    int max;
    cin >> max;

    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            for(int k = j+1; k < N; k++) {
                if(arr[i] + arr[j] + arr[k] <= max && result < arr[i] + arr[j] + arr[k]) {
                    result = arr[i] + arr[j] + arr[k];
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}