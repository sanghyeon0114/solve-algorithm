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
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        for(int j = (N-i); j > 0; j--) {
            cout << "*";
        }
        for(int j = (N-i-1); j > 0; j--) {
            cout << "*";
        }
        cout << "\n";
    }
    for(int i = 1; i < N; i++) {
        for(int j = (N-i-1); j > 0; j--) {
            cout << " ";
        }
        for(int j = 0; j <= i; j++) {
            cout << "*";
        }
        for(int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }




    return 0;
} 