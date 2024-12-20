#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int compare(const string& o1, const string& o2) {
    if(o1.length() == o2.length()) {
        return o1 < o2;
    }
    return o1.length() < o2.length();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;
    vector<string> arr;
    string input;

    for(int i = 0; i < N; i++) {
        cin >> input;
        if(find(arr.begin(), arr.end(), input) == arr.end()) {
            arr.push_back(input);
        } 
    }
    
    sort(arr.begin(), arr.end(), compare);
    for(const string& s : arr) {
        cout << s << endl;
    }

    return 0;
}