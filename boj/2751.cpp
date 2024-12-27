#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    bool num[2000001];


    for(int i = 0; i < 2000001; i++) {
        num[i] = false;
    }

    int N;
    cin >> N;


    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        num[n+1000000] = true;
    }

    for(int i = 0; i < 2000001; i++) {
        if(num[i]) {
            cout << i-1000000 << "\n";
        }
    }

    return 0;
}