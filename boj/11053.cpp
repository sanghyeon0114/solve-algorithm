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

    vector<int> num(N, 0);
    vector<int> order(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> num[i];
        order[i] = 1;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(num[j] < num[i]) {
                order[i] = order[i] < order[j]+1 ? order[j]+1 : order[i];
            }
        }    
    }

    int max = 0;

    for(int i = 0; i < N; i++) {
        if(max < order[i]) {
            max = order[i];
        }
    }

    cout << max << "\n";

    return 0;
}