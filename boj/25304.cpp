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

    int pay;
    cin >> pay;
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        pay -= a*b;
    }

    if(pay == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}