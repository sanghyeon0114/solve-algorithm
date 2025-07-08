#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <sstream>

using namespace std;

ostringstream out;

void bfs(vector<vector<int>> &circuit_list, vector<deque<int>> &arr, int currentindex) {
    for(int i = 0; i < circuit_list[currentindex].size(); i++) {
        if(arr[circuit_list[currentindex][i]].size() != 0) {
            int tmpIndex = arr[circuit_list[currentindex][i]].front(); arr[circuit_list[currentindex][i]].pop_front();
            bfs(circuit_list, arr, tmpIndex);
        } else {
            out << circuit_list[currentindex][i]+1 << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N, 0));
    vector<int> countDegree(N, 0);
    
    bool isPossible = true;

    int edgeCount = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if(graph[i][j] > 0) {
                countDegree[i]+=graph[i][j];
                edgeCount+=graph[i][j];
            }
        }
        if(countDegree[i] % 2) {
            isPossible = false;
        }
    }
    edgeCount /= 2;

    if(!isPossible) {
        cout << -1 << "\n";
        return 0;
    }

    vector<vector<int>> circuit_list;

    while(edgeCount != 0) {
        int start;
        for(int i = 0; i < countDegree.size(); i++) {
            if(countDegree[i] > 0) {
                start = i;
                break;
            }
        }

        vector<int> circuit(0);

        bool isCircuit = false;

        stack<int> s;
        s.push(start);
        while(!s.empty()) {
            int cur = s.top(); s.pop();
            circuit.push_back(cur);
            if(cur == start) {
                if(!isCircuit) {
                    isCircuit = true;
                } else {
                    circuit_list.push_back(circuit);
                    break;
                }
            }
            for(int i = 0; i < N; i++) {
                if(graph[cur][i]) {
                    s.push(i);
                    graph[cur][i]--;
                    graph[i][cur]--;
                    countDegree[cur]--;
                    countDegree[i]--;
                    edgeCount--;
                    break;
                }
            }
        }
    }

    if(circuit_list.size() == 1) {
        for(int j = 0; j < circuit_list[0].size(); j++) {
            cout << circuit_list[0][j]+1 << " ";
        }
        return 0;
    }

    vector<deque<int>> arr(1001, deque<int>(0));

    for(int i = 1; i < circuit_list.size(); i++) {
        arr[circuit_list[i][0]].push_back(i);
    }

    
    bfs(circuit_list, arr, 0);
    cout << out.str();

    return 0;
}