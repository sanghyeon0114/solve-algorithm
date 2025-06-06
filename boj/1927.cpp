#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if(num == 0) {
            if(pq.empty()) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
            continue;
        }
        
        pq.push(num);
    }

    return 0;
}