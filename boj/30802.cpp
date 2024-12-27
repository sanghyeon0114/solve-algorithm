#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    int size[6];
    for(int i = 0; i < 6; i++) {
        cin >> size[i];
    }

    int T, P;
    cin >> T >> P;

    int total1 = 0;

    for(int i = 0; i < 6; i++) {
        total1 += size[i]/T;
        if(size[i]%T!=0) {
            total1++;
        }
    }
    cout << total1 << endl;

    int sum = size[0]+size[1]+size[2]+size[3]+size[4]+size[5];

    cout << sum/P << " " << sum%P << endl;

    return 0;
}