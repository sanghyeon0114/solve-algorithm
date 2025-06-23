#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;

int main() {

    const int MAX = 100000;

    int N, K;
    cin >> N >> K;

    vector<int> time(MAX+1, MAX);
    deque<int> position;

    time[N] = 0;
    position.push_back(N);

    while(!position.empty()) {
        int pos = position.front(); position.pop_front();

        if(pos != 0) {
            for(int i = pos; i <= MAX; i*=2) {
                if(time[pos] < time[i]) {
                    time[i] = time[pos];
                    position.push_front(i);
                }
            }
        }

        if(time[pos]+1 < time[pos-1]) {
            time[pos-1] = time[pos]+1;
            position.push_back(pos-1);
        }
        if(time[pos]+1 < time[pos+1]) {
            time[pos+1] = time[pos]+1;
            position.push_back(pos+1);
        }
    }
    
    cout << time[K] << "\n";


    return 0;
}