#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    int N;
    cin >> N;
    cin.ignore();

    vector<vector<int>> v(N+1, vector<int>(0)); 

    int A, B;
    for(int i = 0; i < N-1; i++) {
        cin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    
    int arr[N+1] = {1, 1, 0, };
    queue<int> order;
    order.push(1);
    while(!order.empty()) {
        int num = order.front(); order.pop();
        for(int i = 0; i < v[num].size(); i++) {
            if(arr[v[num][i]] == 0) {
                order.push(v[num][i]);
                arr[v[num][i]] = num;
            }
        }
    }

    for(int i = 2; i < N+1; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}