#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int node;
    int vertex;
    cin >> node >> vertex;

    int graph[node+1][node+1] = {0, };
    int visit[node+1] = {0, };

    for(int i = 0; i < vertex; i++) {
        int start, end;
        cin >> start >> end;
        graph[start][end] = graph[end][start] = 1;
    }

    queue<int> q;
    q.push(1);
    int count = 0;
    visit[1] = 1;

    while(!q.empty()) {
        int com = q.front(); q.pop();
        if(visit[com] == 0) {
            visit[com] = 1;
            count++;
        }
        for(int i = 1; i <= node; i++) {
            if(visit[i] == 0 && graph[com][i] == 1) {
                q.push(i);
            }
        }
    }

    cout << count << "\n";

    return 0;
}