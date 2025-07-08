#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    string numbers;
    cin >> numbers;

    vector<int> arr(13);
    vector<int> mul = {1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3};

    for(int i = 0; i < 13; i++) {
        if(numbers.at(i) == '*') {
            arr[i] = -1;
        } else {
            arr[i] = numbers.at(i) - '0';
        }
    }

    for(int i = 0; i < 10; i++) {
        int sum = 0;
        for(int j = 0; j < 12; j++) {
            if(arr[j] == -1) {
                sum += i * mul[j];
            } else {
                sum += arr[j] * mul[j]; 
            }
        }
        sum %= 10;
        if(((10 - sum) % 10) == arr[12]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}