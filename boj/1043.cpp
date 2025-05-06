#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    
    int p;
    cin >> p;
    bool never[N+1] = {0, };
    for(int i = 0; i < p; i++) {
        int n;
        cin >> n;
        never[n] = 1;
    }
    vector<vector<int>> vq(M);
    int graph[N+1][N+1] = {0, };

    for(int i = 0; i < M; i++) {
        int n;
        cin >> n;

        for(int j = 0; j < n; j++) {
            int n2;
            cin >> n2;
            vq[i].push_back(n2);
        }
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                graph[vq[i][j]][vq[i][k]] = graph[vq[i][k]][vq[i][j]] = 1;
            }
        }
    }

    // 수정 필요
    for(int k = 1; k <= N; k++) {
        for(int i = 1 ; i <= N; i++) {
            if(!never[i]) {
                continue;
            }
            for(int j = 1; j <= N; j++) {
                if(graph[i][j]) {
                    never[j] = 1;
                }
            }
        }
    }


    int count = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < vq[i].size(); j++) {
            if(never[vq[i][j]]) {
                count++;
                break;
            }
        }
    }
    cout << M-count << "\n";

    return 0;
} 