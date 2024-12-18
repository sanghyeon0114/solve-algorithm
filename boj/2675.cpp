#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int count[N];
    string input[N];

    for(int i = 0; i < N; i++) {
        cin >> count[i];
        cin >> input[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < input[i].size(); j++) {
            for(int k = 0; k < count[i]; k++) {
                cout << input[i].at(j);
            }
        }
        cout << endl;
    }

    return 0;
}