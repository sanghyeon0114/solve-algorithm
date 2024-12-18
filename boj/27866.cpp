#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    string input;
    int N;

    cin >> input >> N;

    cout << input.at(N-1) << endl;

    return 0;
}