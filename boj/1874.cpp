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

    int N;
    cin >> N;

    queue<int> answer;
    queue<int> order;

    stack<int> s;

    for(int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        answer.push(num);
        order.push(i);
    }

    string result = "";

    while(!answer.empty()) {
        int num = answer.front();
        if(!s.empty() && s.top() == num) {
            s.pop();
            result.append("-\n");
            answer.pop();
        } else {
            if(order.empty() || order.front() > answer.front()) {
                result = "NO";
                break;
            }
            while(!order.empty() && order.front() <= answer.front()) {
                s.push(order.front()); order.pop();
                result.append("+\n");
            }
        }
    }

    cout << result;

    return 0;
}