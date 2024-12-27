#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        int stack = 0;
        bool OK = true;

        for(int j = 0; j < input.length(); j++) {
            if(input.at(j) == '(') {
                stack++;
            } else if(input.at(j) == ')') {
                stack--;
            }
            if(stack < 0) {
                OK = false;
                break;
            }
        }
        if(stack != 0) {
            OK = false;
        }
        if(OK) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}