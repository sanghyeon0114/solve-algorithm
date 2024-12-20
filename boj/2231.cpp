#include <iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    int N;
    cin >> N;
    
    int tmp = 0, div;
    int result = 0;

    for(int i = 1; i < N; i++) {
        tmp += i;
        div = i;
        while(div != 0) {
            tmp += div % 10;
            div /= 10;
        }

        if(tmp == N) {
            result = i;
            break;
        }
        tmp = 0;
    }

    cout << result << endl;

    return 0;
}