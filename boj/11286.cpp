#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

struct AbsNum {
    long value;
    AbsNum(long v) : value(v) {}

    bool operator<(const AbsNum n) const {
        if(abs(this->value) == abs(n.value)) {
            return this->value > n.value;
        }
        return abs(this->value) > abs(n.value);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<AbsNum> pq;
    ostringstream out;

    for(int i = 0; i < N; i++) {
        long num;
        cin >> num;

        if(num == 0) {
            if(pq.empty()) {
                out << 0 << "\n";
            } else {
                out << pq.top().value << "\n";
                pq.pop();
            }
        } else {
            pq.push(AbsNum(num));
        }
    }

    cout << out.str();
    
    return 0;
}