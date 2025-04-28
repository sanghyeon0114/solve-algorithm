#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    unordered_map<string, int> map;

    string str[N+K];
    list<string> l;

    for(int i = 0; i < N+K; i++) {
        cin >> str[i];
        if(map.find(str[i]) != map.end()) {
            map[str[i]]++;
            l.push_back(str[i]);
        } else {
            map.insert({str[i], 1});
        }
    }

   l.sort();

    cout << l.size() << "\n";

    while(!l.empty()) {
        cout << l.front() << "\n";
        l.pop_front();
    }

    return 0;
}