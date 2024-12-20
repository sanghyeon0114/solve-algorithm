#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    int two = 0;
    int five = 0;
    int ten = 0;
    int num;

    for(int i = 2; i <= N; i++) {
        num = i;
        while(num % 10 == 0) {
            num /= 10;
            ten++;
        }
        while(num % 5 == 0) {
            num /= 5;
            five++;
        }
        while(num % 2 == 0) {
            num /= 2;
            two++;
        }
    }

    cout << (five <= two ? five : two) + ten << endl;

    return 0;
}