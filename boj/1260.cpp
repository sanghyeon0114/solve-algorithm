#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N+1, vector<int>(0));

    for(int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    stack<int> s;
    s.push(V);

    vector<bool> dfs(N+1, false);

    while(!s.empty()) {
        int cur = s.top(); s.pop();
        if(!dfs[cur]) {
            cout << cur << " ";
        }
        dfs[cur] = true;

        for(int i = 0; i < graph[cur].size(); i++) {
            if(cur == graph[cur][i] || dfs[graph[cur][i]]) {
                continue;
            }
            s.push(graph[cur][i]);
        }
    }

    cout << "\n";

    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    queue<int> q;
    q.push(V);

    vector<bool> bfs(N+1, false);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(!bfs[cur]) {
            cout << cur << " ";
        }
        bfs[cur] = true;

        for(int i = 0; i < graph[cur].size(); i++) {
            if(cur == graph[cur][i] || bfs[graph[cur][i]]) {
                continue;
            }
            q.push(graph[cur][i]);
        }
    }

    cout << "\n";

    return 0;
}