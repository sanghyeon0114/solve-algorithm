#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    int result = 0;
    int tmp;
    cin >> N;

    result += N/5;
    tmp  = N%5;

    while(result >= 0) {
        if(tmp % 3 == 0) {
            result += tmp/3;
            break;
        }
        result -= 1;
        tmp += 5;
    }

    if(result == -1) {
        cout << "-1\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}