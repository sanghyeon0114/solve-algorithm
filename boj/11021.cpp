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

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;

        cout << "Case #" << (i+1) << ": " << (A+B) << "\n";
    }

    return 0;
} 