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

    bool isWhite = true;

    int count = 0;
    
    for(int i = 0; i < 8; i++) {
        isWhite = (i % 2 == 0);
        for(int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            
            if(isWhite) {
                if(c == 'F') {
                    count++;
                }
            }

            isWhite = !isWhite;
        }
    }

    cout << count << "\n";

    return 0;
}
