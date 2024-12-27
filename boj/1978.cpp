#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    bool arr[1001] = {true,};
    arr[0] = arr[1] = false;
    int index = 2;

    for(int i = 0; i <= 1000; i++) {
        arr[i] = true;
    }
    arr[1] = false;
    arr[0] = false;
    
    while(index <= 1000) {
        for(int i = index*2; i <= 1000; i+=index) {
            arr[i] = false;
        }
        while(!arr[++index]);
    }

    int N;
    cin >> N;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if(arr[num]) {
            sum++;
        }
    }
    cout << sum << "\n";
    
    return 0;
}