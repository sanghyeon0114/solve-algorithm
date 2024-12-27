#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

queue<int> s;

void push(int num) {
    s.push(num);
}

int pop() {
    if(s.size() == 0) {
        return -1;
    }
    int n = s.front();
    s.pop();
    return n;
}

int size() {
    return s.size();
}

int empty() {
    if(s.empty()) {
        return 1;
    }
    return 0;
}

int front() {
    if(s.size() == 0) {
        return -1;
    }
    return s.front();
}

int back() {
    if(s.size() == 0) {
        return -1;
    }
    return s.back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    int N;
    cin >> N;
    cin.ignore();

    string command, result = "";
    string cmd1;
    int cmd2;

    for(int i = 0; i < N; i++) {
        getline(cin, command);
        istringstream iss(command);

        iss >> cmd1 >> cmd2;

        if(cmd1 == "push") {
            push(cmd2);
        } else if(cmd1 == "pop") {
            result.append(to_string(pop()));
            result.append("\n");
        } else if(cmd1 == "size") {
            result.append(to_string(size()));
            result.append("\n");
        } else if(cmd1 == "empty") {
            result.append(to_string(empty()));
            result.append("\n");
        } else if(cmd1 == "front") {
            result.append(to_string(front()));
            result.append("\n");
        } else if(cmd1 == "back") {
            result.append(to_string(back()));
            result.append("\n");
        }
    }
    
    cout << result << endl;

    return 0;
}