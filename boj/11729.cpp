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

void recur(int start, int middle, int end, int& count, int max, string &str) {
    if(max == 0) {
        return;
    }
    recur(start, end, middle, count, max-1, str);
    str.append(to_string(start));
    str.append(" ");
    str.append(to_string(end));
    str.append("\n");
    count++;
    recur(middle, start, end, count, max-1, str);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;
    int count = 0;
    string result = "";
    recur(1, 2, 3, count, N, result);
    cout << count << "\n";
    cout << result;

    return 0;
} 