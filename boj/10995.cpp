#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    long N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        if(i % 2 == 1) {
            cout << " ";
        }
        for(int j = 0; j < N*2; j++) {
            if(j % 2 == 0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
} 