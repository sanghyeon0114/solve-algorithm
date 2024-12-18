#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string trim(string str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string input, token;
    getline(cin, input);

    input = trim(input);

    istringstream iss3(input);
    vector<string> tokens;
    while(getline(iss3, token, ' ')){
        tokens.push_back(token);
    }

    cout << tokens.size() << endl;

    return 0;
}                                                              