#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int sum = 0;
    int num;

    for(int i = 0; i < 5; i++) {
        cin >> num;
        sum += num*num;
    }

    cout << sum % 10 << endl;

    return 0;
}