#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <unordered_map>

using namespace std;

long long pow(int A, int B, int C) {
    if(B == 0) {
        return 1;
    }
    if(B == 1) {
        return A % C;
    }
    long long num = pow(A, B/2, C) % C;
    if(B % 2 == 0) {
        return (num * num) % C;
    } else {
        return (((num * num) % C) * (A % C)) % C;
    }
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    
    cout << pow(A, B, C);

    return 0;
}