#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    while(true) {
        int A,B,C;
        cin >> A >> B >> C;
        if(A == 0 && B ==0 && C == 0) {
            break;
        }

        if(A*A + B*B == C*C || A*A + C*C == B*B || C*C + B*B == A*A) {
            cout << "right" << "\n";
        } else {
            cout << "wrong" << "\n";
        }
    }
    return 0;
}