#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    long A, B;
    cin >> A >> B;

    if(A - B >= 0)
        cout << A - B << endl;
    else
    cout << B - A << endl;
    return 0;
}