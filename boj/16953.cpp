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
#include <time.h>

using namespace std;

struct Number {
    long current;
    long order;
};

int main() {
    long A, B;
    cin >> A >> B;

    queue<Number> qn;
    Number start = {A, 0};
    qn.push(start);

    bool isExist = false;

    while(!qn.empty()) {
        Number num = qn.front(); qn.pop();
        if(num.current == B) {
            cout << num.order+1 << "\n";
            isExist = true;
            break;
        }
        if(num.current*2 <= B) {
            qn.push({num.current*2, num.order+1});
        }
        if(num.current*10+1 <= B) {
            qn.push({num.current*10+1, num.order+1});
        }
    }

    if(!isExist) {
        cout << -1 << "\n";
    }

    return 0;
}