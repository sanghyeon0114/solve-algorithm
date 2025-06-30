#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <unordered_map>

using namespace std;

void bt(vector<int> &num, int current, int end, vector<int> result) {
    if(current == end) {
        for(int num : result) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < num.size(); i++) {
        if(!result.empty() && num[i] < result.back()) {
            continue;
        }
        vector<int> result2 = result;
        result2.push_back(num[i]);
        bt(num, current+1, end, result2);

    }
}

int main() {

    int M, N;
    cin >> M >> N;

    
    vector<int> num(M, 0);

    for(int i = 0; i < num.size(); i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    bt(num, 0, N, {});

    return 0;
}