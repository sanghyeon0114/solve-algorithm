#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int numCount[42] = {0,};
    int result = 0;

    for(int i = 0; i < 10; i++) {
        int num;
        cin >> num;

        numCount[num % 42]++;
    }

    for(int i = 0; i < 42; i++) {
        if(numCount[i] != 0) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}