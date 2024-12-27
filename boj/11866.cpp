#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    int K;
    cin >> N >> K;

    queue<int> circle, result;
    for(int i = 1; i <= N; i++) {
        circle.push(i);
    }

    int index = 0;

    while(!circle.empty()) {
        index++;
        int num = circle.front();
        if(index % K == 0) {
            result.push(num);
        }
        circle.pop();
        if(index % K != 0) {
            circle.push(num);
        }
    }

    cout << "<";
    while(!result.empty()) {
        cout << result.front();
        if(result.size() != 1) {
            cout << ", ";
        }
        result.pop();
    }

    cout << ">\n";

    return 0;
}