#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int M, N;

void print(vector<int> &v, int order, string str, bool isNum[]) {
    if(order > N) {
        cout << str << "\n";
        return;
    }
    for(int i = 0; i < M; i++) {
        if(!isNum[i]) {
            isNum[i] = 1;
            string newStr = str+to_string(v[i])+" ";
            print(v, order+1, newStr, isNum);
            isNum[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    cin >> M >> N;
    cin.ignore();

    vector<int> v(M, 0);
    
    for(int i = 0; i < M; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    bool isNum[M] = {0,};
    string str = "";
    print(v, 1, str, isNum);

    return 0;
}