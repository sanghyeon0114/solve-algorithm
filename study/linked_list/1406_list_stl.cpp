#include <iostream>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    string input;
    cin >> input;

    list<char> editor(0);
    for(char in : input) {
        editor.push_back(in);
    }

    list<char>::iterator cursor = editor.end();

    int len;
    cin >> len;

    for(int i = 0; i < len; i++) {
        char comm;
        cin >> comm;

        if(comm == 'L') {
            if(cursor != editor.begin()) {
                cursor--;
            }
        } else if(comm == 'D') {
            if(cursor != editor.end()) {
                cursor++;
            }
        } else if(comm == 'B') {
            if(cursor == editor.begin()) {
                continue;
            }

            cursor--;
            cursor = editor.erase(cursor);
            
        } else if(comm == 'P') {
            char newChar;
            cin >> newChar;
            editor.insert(cursor, newChar);
        }
    }

    for(char output : editor) {
        cout << output;
    }
    cout << "\n";
     
    return 0;
}