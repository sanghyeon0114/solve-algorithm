#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    int A, B, C;
        
    int H = 0, W = 1;
    int result[N];

    for(int i = 0; i < N; i++) {
        cin >> A >> B >> C;
        
        H = C;
        int add = 0;
        while(H - A > 0) { H -= A; add += 1; }
        W += add;

        cout << ((A >= 10 && H < 10) ? "0" : "") << H << ((B >= 10 && W < 10) ? "0" : "") << W << endl;
        H = 1;
        W = 1;
    }

    return 0;
}