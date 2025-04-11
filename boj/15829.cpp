#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int L;
    cin >> L;
    long sum = 0;
    long r = 1;
    for(int i = 0; i < L; i++) {
        char str;
        cin >> str;
        sum += (str-96) * r;
        sum %= 1234567891;
        r *= 31;
        r %= 1234567891;
    }

    cout << sum << endl;

    return 0;
}