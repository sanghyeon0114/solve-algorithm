#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int recursion(int x, int y, int len, int& number, int r, int c) {
    if(len == 1) {
        return number;
    }
    if(r < x + len/2) {
        if(c < y + len/2) {
            number += 0;
            return recursion(x, y, len/2, number, r, c);
        } else {
            number += ((len/2) * (len/2));
            return recursion(x, y + len/2, len/2, number, r, c);
        }
    } else {
        if(c < y + len/2) {
            number += ((len/2) * (len/2)) * 2;
            return recursion(x + len/2, y, len/2, number, r, c);
        } else {
            number += ((len/2) * (len/2)) * 3;
            return recursion(x + len/2, y + len/2, len/2, number, r, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, r, c;
    cin >> N >> r >> c;

    int len = (int)pow(2, N);

    int number = 0;
    recursion(0, 0, len, number, r, c);

    cout << number << "\n";
    return 0;
}