#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    stack<int> s;

    while((N--) > 0) {
        int num;
        cin >> num;

        if(num == 0) {
            s.pop();
            continue;
        }
        s.push(num);
    }

    int sum = 0;
    while(!s.empty()) {
        sum += s.top(); s.pop();
    }

    cout << sum << "\n";

    return 0;
}