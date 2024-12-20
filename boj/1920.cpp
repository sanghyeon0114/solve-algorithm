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

    unordered_map<int, bool> arr;

    int num;

    for(int i = 0; i < N; i++) {
        cin >> num;
        arr.insert({num, true});
    }

    cin >> N;

    string result = "";

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if(arr.find(num) == arr.end()) {
            result.append("0\n");
        } else {
            result.append(to_string(arr.find(num)->second));
            result.append("\n");
        }
    }

    cout << result << endl;

    return 0;
}