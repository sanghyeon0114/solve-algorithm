#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

struct Position {
    int pos;
    int time;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    bool visit[100001] = {false, };
    queue<Position> q;

    q.push({N, 0});

    while(!q.empty()) {
        Position cur = q.front(); q.pop();
        if(cur.pos == K) {
            cout << cur.time << "\n";
            break;
        }
        int time = cur.time + 1;
        if(cur.pos - 1 >= 0 && !visit[cur.pos-1]) {
            q.push({cur.pos-1, time});
            visit[cur.pos-1] = true;
        }
        if(cur.pos + 1 <= 100000 && !visit[cur.pos+1]) {
            q.push({cur.pos+1, time});
            visit[cur.pos+1] = true;
        }
        if(cur.pos * 2 <= 100000 && !visit[cur.pos*2]) {
            q.push({cur.pos * 2, time});
            visit[cur.pos*2] = true;
        }
    }

    return 0;
}