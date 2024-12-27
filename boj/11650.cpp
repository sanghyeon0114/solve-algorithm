#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Pos {
    int x;
    int y;
};

bool compare(Pos p1, Pos p2) {
    if(p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    vector<Pos> arr;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }

    sort(arr.begin(), arr.end(), compare);

    for(Pos p : arr) {
        cout << p.x << " " << p.y << "\n";
    }

    return 0;
}