#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int arr[10001];

    for(int i = 0; i <= 10000; i++) {
        arr[i] = 0;
    }

    int N;
    cin >> N;

    int num;

    for(int i = 0; i < N; i++) {
        cin >> num;
        arr[num]++;
    }
    

    for(int i = 0; i <= 10000; i++) {
        for(int j = 0; j < arr[i]; j++) {
            cout << i << "\n";
        }
    }

    return 0;
}