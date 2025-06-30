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

    int N, M;
    cin >> N;
    cin >> M;

    vector<vector<long>> map(N+1, vector<long>(N+1, -1));
    for(int i = 0; i < M; i++) {
        int start, end;
        long distance;
        cin >> start >> end >> distance;
        if(map[start][end] == -1 || map[start][end] > distance) { // check : 이 부분 생각을 못함;;
            map[start][end] = distance;
        }
    }

    int A, B;
    cin >> A >> B;

    vector<long> minDistance(N+1, __LONG_MAX__);
    minDistance[A] = 0;
    
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
    pq.push({0, A});

    while(!pq.empty()) {
        auto [distance, node] = pq.top(); pq.pop();

        for(int i = 1; i <= N; i++) {
            if(node == i) {
                continue;
            }
            if(map[node][i] != -1 && minDistance[i] > distance+map[node][i]) {
                minDistance[i] = distance+map[node][i];
                pq.push({minDistance[i], i});
            }
        }
    }

    cout << minDistance[B] << "\n";

    return 0;
}

/*
2
2
1 2 0
1 2 10
1 2

-> 0

*/