#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;
    
    int count[201] = {0, }; // N+100

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        count[num+100]++;
    }

    int maxNum;
    cin >> maxNum;

    cout << count[maxNum+100] << "\n";

    return 0;
}
