#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    int num = 666;
    int start = 0;
    
    while(true) {
        string num_str = to_string(num);
        if(num_str.find("666") != -1) {
            start++;
        }
        if(start == N) {
            cout << num_str << endl;
            break;
        }
        num++;
    }
    return 0;
}