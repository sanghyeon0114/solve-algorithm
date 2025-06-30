#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    string first, second;
    cin >> first;
    cin >> second;
    
    vector<char> fv;
    vector<char> sv;
    char secondLast = second[second.length()-1];

    for(int i = 0; i < first.length(); i++) {
        fv.push_back(first[i]);
    }
    for(int i = second.length()-1; i >= 0; i--) {
        sv.push_back(second[i]);
    }

    deque<char> printString;
    for(int i = 0; i < fv.size(); i++) {
        printString.push_back(fv[i]);
        if(fv[i] == secondLast && printString.size() >= second.length()) {
            bool isSame = true;
            for(int j = 1; j < second.length(); j++) {
                if(printString[printString.size()-1-j] != sv[j]) {
                    isSame = false;
                    break;
                }
            }
            if(isSame) {
                for(int j = 0; j < second.length(); j++) {
                    printString.pop_back();
                }
            }
        }
    }
    if(printString.empty()) {
        cout << "FRULA" << "\n";
    } else {
        while(!printString.empty()) {
            cout << printString.front();
            printString.pop_front();
        }
        cout << "\n";
    }

    return 0;
}