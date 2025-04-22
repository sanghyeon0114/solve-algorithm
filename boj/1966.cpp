#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Number {
    int num;
    int order;
};

bool compare(Number e1, Number e2) {
    return e1.num > e2.num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int testcase;
    cin >> testcase;

    while((testcase--) > 0) {
        int N;
        int M;

        cin >> N >> M;  

        queue<Number> q;
        vector<Number> v;

        for(int i = 0; i < N; i++) {
            int num;
            cin >> num;
            Number ns = {num, i};
            q.push(ns);
            v.push_back(ns);
        }

        sort(v.begin(), v.end(), compare);
        int result = 0;
        int order = 0;

        while(order < N) {
            if(q.front().num == v[order].num) {
                if(q.front().order == M) {
                    result = order;
                    break;
                }
                q.pop();
                order++;
            } else {
                q.push(q.front());
                q.pop();
            }
        }
        cout << result+1 << "\n";
    }

    return 0;
}