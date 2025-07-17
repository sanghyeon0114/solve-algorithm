#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

struct Number {
    long value;
    Number(long v) : value(v) {}

    bool operator<(const Number n) const {
        return this->value < n.value;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<Number> pq;
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
            pq.push(Number(num));
        }
    }

    cout << out.str();
    
    return 0;
}