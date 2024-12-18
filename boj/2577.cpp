#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int numCount[10] = {0,};

    int A,B,C;
    cin >> A >> B >> C;

    int sum = A*B*C;

    while(sum != 0) {
        int num = sum%10;
        sum /= 10;
        numCount[num]++;
    }

    for(int i = 0; i < 10; i++) {
        cout << numCount[i] << endl;
    }

    return 0;
}