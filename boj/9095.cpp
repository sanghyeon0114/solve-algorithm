#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

void getCount(int num, int& count) {
    if(num == 0) {
        count++;
        return;
    }
    if(num >= 3) {
        getCount(num-3, count);
    }
    if(num >= 2) {
        getCount(num-2, count);
    }
    if(num >= 1) {
        getCount(num-1, count);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;
    
    while((N--) > 0) {
        int num;
        cin >> num;
        int count = 0;
        getCount(num, count);

        cout << count << "\n";
    }

    return 0;
}