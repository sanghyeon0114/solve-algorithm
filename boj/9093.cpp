#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

vector<string> split(string& str, char d) {
    stringstream ss(str);
    string token;
    vector<string> splited;
    while(getline(ss, token, d)) {
        splited.push_back(token);
    }
    return splited;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();

    for(int i = 0; i < N; i++) {
        string str;
        getline(cin, str);
        vector<string> vs = split(str, ' ');

        for(int j = 0; j < vs.size(); j++) {
            stack<char> sc;
            for(int k = 0; k < vs[j].size(); k++) {
                sc.push(vs[j][k]);
            }
            while(!sc.empty()) {
                cout << sc.top();
                sc.pop();
            }
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
} 