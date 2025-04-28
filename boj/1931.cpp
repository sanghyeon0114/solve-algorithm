#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

struct Time {
    int start;
    int end;
};

bool ops(Time t1, Time t2) {
    if(t1.end != t2.end) {
        return t1.end > t2.end;
    } else {
        return t1.start > t2.start;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    vector<Time> times;

    for(int i = 0; i < N; i++) {
        Time t;
        cin >> t.start >> t.end;
        times.push_back(t);
    }

    sort(times.begin(), times.end(), ops);

    int count = 0;
    int end = 0;
    while(!times.empty()) {
        Time t = times.back(); times.pop_back();
        if(end <= t.start) {
            count++;
            end = t.end;
        }
    }  
    cout << count << "\n";

    return 0;
}