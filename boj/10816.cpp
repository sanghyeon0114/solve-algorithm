#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;
    map<int, int> card;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if(card.find(num) != card.end()) {
            card[num]++;
        } else {
            card[num] = 1;
        }
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if(card.find(num) != card.end()) {
            cout << card[num] << " ";
        } else {
            cout << "0 ";
        }
    }
    cout << endl;

    return 0;
}