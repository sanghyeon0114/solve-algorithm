#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    string num;
    cin >> num;

    int sum = 0;

    for(int i = 0; i < num.size(); i++) {
        sum += (int)num.at(i) - 48;
    }

    cout << sum << endl;

    return 0;
}