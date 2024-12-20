#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    while(1) {
        string N;
        cin >> N;

        if(N == "0") {
            break;
        }

        int len = N.length();

        string str1 = N.substr(0,len/2);
        string str2 = N.substr(len/2, len);

        if(N.length() % 2 == 1) {
            str2 = str2.substr(1, str2.length());
        }

        reverse(str2.begin(), str2.end());

        if(str1 == str2) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}