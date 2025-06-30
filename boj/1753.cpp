#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>

using namespace std;

struct Position {
    int node;
    int distance;
};

struct cmp{
    bool operator()(Position& p1, Position& p2) {
        if(p1.distance == p2.distance) {
            return p1.node > p2.node;
        }
        return p1.distance > p2.distance;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;
    cin >> N;
    cin >> M;

    int start;
    cin >> start;

    vector<vector<Position>> nodes(N+1, vector<Position>{});
    
    for(int i = 0; i < M; i++) {
        int sn, en, dis;
        cin >> sn >> en >> dis;
        Position pos = {en, dis};
        nodes[sn].push_back(pos);
    }

    priority_queue<Position, vector<Position>, cmp> pq;

    vector<int> minDistance(N+1, __INT_MAX__);
    vector<bool> visited(N+1, false);

    minDistance[start] = 0;
    pq.push({start, 0});

    while(!pq.empty()) {
        Position pos = pq.top(); pq.pop();
        int distance = pos.distance;
        int node = pos.node;

        if(visited[node]) {
            continue;
        }
        visited[node] = true;

        for(Position pos2 : nodes[node]) {
            if(minDistance[pos2.node] > minDistance[node] + pos2.distance) {
                minDistance[pos2.node] = minDistance[node] + pos2.distance;
                pq.push({pos2.node, minDistance[pos2.node]});
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(minDistance[i] == __INT_MAX__) {
            cout << "INF" << "\n";
        } else {
            cout << minDistance[i] << "\n";
        }
    }

    return 0;
}
