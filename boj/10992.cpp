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

    for(int i = 0; i < N-1; i++) {
        for(int j = (N-i-1); j > 0; j--) {
            cout << " ";
        }
        cout << "*";
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        for(int j = 1; j < i; j++) {
            cout << " ";
        }
        if(i != 0) {
            cout << "*";
        }
        cout << "\n";
    }

    for(int i = 0; i < N*2-1; i++) {
        cout << "*";
    }
    cout << "\n";

    return 0;
} 