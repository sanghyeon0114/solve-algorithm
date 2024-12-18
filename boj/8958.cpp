#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    string OX[N];
    
    for(int i = 0; i < N; i++) {
         cin >> OX[i];
    }

    int total, recent;

    for(int i = 0; i < N; i++) {
        total = 0;
        recent = 0;
        for(int j = 0; j < OX[i].size(); j++) {
            if(OX[i].at(j) == 'O') {
                recent += 1;
            } else {
                recent = 0;
            }
            total += recent;
        }
        cout << total << endl;
    }

    return 0;
}