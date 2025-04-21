#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Position {
    int x;
    int y;
};


bool compare(const Position &e1, const Position &e2) { // compare 함수는 int가 아닌 bool 타입으로.
    if(e1.y == e2.y) {
        return e1.x < e2.x;
    }
    return e1.y < e2.y; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    vector<Position> arr;

    while((N--) > 0) {
        Position input;
        cin >> input.x >> input.y;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end(), compare);

    for(Position e : arr) {
        cout << e.x << " " << e.y << "\n"; // endl 쓰지 않는 것을 항상 유의하기
    }
    
    return 0;
}