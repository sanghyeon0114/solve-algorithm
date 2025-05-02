#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

struct Number {
    int num;
    int order;
    int zip;
};

bool ops1(Number n1, Number n2) {
    return n1.num < n2.num;
}

bool ops2(Number n1, Number n2) {
    return n1.order < n2.order;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;
    vector<Number> arr(N);

    for(int i = 0; i < N; i++) {
        cin >> arr[i].num;
        arr[i].order = i;
    }

    sort(arr.begin(), arr.end(), ops1);

    arr[0].zip = 0;

    for(int i = 1; i < N; i++) {
        if(arr[i-1].num == arr[i].num) {
            arr[i].zip = arr[i-1].zip;
        } else {
            arr[i].zip = arr[i-1].zip + 1;
        }
    }

    sort(arr.begin(), arr.end(), ops2);

    for(int i = 0; i < N; i++) {
        cout << arr[i].zip << " ";
    }


    return 0;
}