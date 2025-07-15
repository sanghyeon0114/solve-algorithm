#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, string> m;

    for(int i = 0; i < N; i++) {
        string site, passwd;
        cin >> site;
        cin >> passwd;
        m.insert({site, passwd});
    }

    ostringstream out;

    for(int i = 0; i < M; i++) {
        string site;
        cin >> site;
        out << m[site] << "\n";
    }

    cout << out.str();
    
    return 0;
}