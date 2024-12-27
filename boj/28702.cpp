#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    string n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    if(n1 != "Fizz" && n1 != "Buzz" && n1 != "FizzBuzz") {
        int num = stoi(n1) + 3;
        if(num % 15 == 0) {
            cout << "FizzBuzz" << endl;
        } else if(num % 5 == 0) {
            cout << "Buzz" << endl;
        } else if(num % 3 == 0) {
            cout << "Fizz" << endl;
        } else {
            cout << num << endl;
        }
    } else if(n2 != "Fizz" && n2 != "Buzz" && n2 != "FizzBuzz") {
        int num = stoi(n2) + 2;
        if(num % 15 == 0) {
            cout << "FizzBuzz" << endl;
        } else if(num % 5 == 0) {
            cout << "Buzz" << endl;
        } else if(num % 3 == 0) {
            cout << "Fizz" << endl;
        } else {
            cout << num << endl;
        }
    } else if(n3 != "Fizz" && n3 != "Buzz" && n3 != "FizzBuzz") {
        int num = stoi(n3) + 1;
        if(num % 15 == 0) {
            cout << "FizzBuzz" << endl;
        } else if(num % 5 == 0) {
            cout << "Buzz" << endl;
        } else if(num % 3 == 0) {
            cout << "Fizz" << endl;
        } else {
            cout << num << endl;
        }
    }

    return 0;
}