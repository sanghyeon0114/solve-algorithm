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
    cin >> N >> M;

    vector<queue<int>> graph(N+1, queue<int>{});
    vector<int> in(N+1, 0);

    queue<int> q;
    
    for(int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push(end);
        in[end]++;
    }

    for(int i = 1; i <= N; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int num = q.front(); q.pop();
        cout << num << " ";

        while(!graph[num].empty()) {
            int next = graph[num].front(); graph[num].pop();
            in[next]--;
            if(in[next] == 0) {
                q.push(next);
            }
        }
    }
    cout << "\n";

    return 0;
}
