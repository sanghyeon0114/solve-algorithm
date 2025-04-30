#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
// #include <stack>
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
    
    bool arr[21] = {false, };

    int N;
    cin >> N;
    cin.ignore();
    
    for(int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if(cmd == "add") {
            int num;
            cin >> num;
            arr[num] = true;
        } else if(cmd == "remove") {
            int num;
            cin >> num;
            arr[num] = false;
        } else if(cmd == "check") {
            int num;
            cin >> num;
            cout << (arr[num] ? 1 : 0) << "\n";
        } else if(cmd == "toggle") {
            int num;
            cin >> num;
            arr[num] = !arr[num];
        } else if(cmd == "all") {
            for(int i = 1; i <= 20; i++) {
                arr[i] = true;
            }
        } else if(cmd == "empty") {
            for(int i = 1; i <= 20; i++) {
                arr[i] = false;
            }
        }
    }

    return 0;
}