#include <iostream>
#include <algorithm>

using namespace std;
    
int gcd(int A, int B) {
    if(B == 0) {
        return A;
    }
    return gcd(B, A%B);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int A,B;
    cin >> A >> B;
    
    int r1 = gcd(A, B);
    if(A > B) {
        cout << r1 << endl;
    } else {
        cout << r1 << endl;
    }

    cout << A*B/r1 << endl;

    return 0;
}