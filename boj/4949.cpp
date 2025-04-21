#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    string str;
    while(getline(cin, str)){
        if(str == ".") {
            break;
        }
        stack<int> s;
        bool isBalanced = true;

        for(char c : str) {
            if(c == '(') {
                s.push(0);
            } else if(c == '[') {
                s.push(1);
            } else if(c == ')') {
                if(!s.empty() && s.top() == 0) {
                    s.pop();
                } else {
                    isBalanced = false;
                    break;
                }
            } else if(c == ']') {
                if(!s.empty() && s.top() == 1) {
                    s.pop();
                } else {
                    isBalanced = false;
                    break;
                }
            }
        }
        if(s.empty() && isBalanced) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}