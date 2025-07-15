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

    map<int, string> m1;
    map<string, int> m2;

    for(int i = 1; i <= N; i++) {
        string name;
        cin >> name;
        m1.insert({i, name});
        m2.insert({name, i});
    }

    ostringstream out;

    for(int i = 0; i < M; i++) {
        string name;
        cin >> name;
        bool isDigit = true;
        for(int j = 0; j < name.size(); j++) {
            isDigit = isdigit(name[j]);
        }
        if(isDigit) {
            int index = stoi(name);
            out << m1[index] << "\n";
        } else {
            out << m2[name] << "\n";
        }
    }

    cout << out.str();
    
    return 0;
}