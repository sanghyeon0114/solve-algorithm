#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int c, d, e, f, g, a, b, C;
    cin >> c >> d >> e >> f >> g >> a >> b >> C;

    if(c==1 && d==2 && e==3 && f==4 && g==5 && a==6 && b==7 && C==8) {
        cout << "ascending" << endl;
    } else if(c==8 && d==7 && e==6 && f==5 && g==4 && a==3 && b==2 && C==1) {
        cout << "descending" << endl;
    } else {
        cout << "mixed" << endl;
    }

    return 0;
}