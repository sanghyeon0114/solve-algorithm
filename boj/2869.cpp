#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    long A, B, V;
    cin >> A >> B >> V;

    long day = 0;
    int up = A - B;

    V -= A;
    day++;

    if(V % up != 0) {
        day++;
    }
    
    day += (V/up);

    cout << day << endl;
    return 0;
}