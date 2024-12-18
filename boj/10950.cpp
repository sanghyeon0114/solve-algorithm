#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;

    cin >> N;

    int arr[N][2];

    for(int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 0; i < N; i++) {
        cout <<  arr[i][0] + arr[i][1] << endl;
    }

    return 0;
}