#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    long inc = 0;
    long N;
    cin >> N;

    if(N == 1) {
        cout << 1 << endl;
        return 0;
    }

    N -= 1;

    long result = 1;

    while(inc < N) {
        N -= inc;
        inc += 6;
        result++;
    }

    cout << result << endl;

    return 0;
}