#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>

using namespace std;

bool checkFull(vector<vector<int>> &arr, int start1, int end1, int start2, int end2) {
    for(int i = start1; i < end1; i++) {
        for(int j = start2; j < end2; j++) {
            if(arr[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool checkFull2(vector<vector<int>> &arr, int start1, int end1, int start2, int end2) {
    for(int i = start1; i < end1; i++) {
        for(int j = start2; j < end2; j++) {
            if(arr[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void getCount(vector<vector<int>> &arr, int start1, int end1, int start2, int end2, int size, int& count1, int& count2, bool is1, bool is2) {
    if(size == 0) {
        return;
    }
    if(checkFull(arr, start1, end1, start2, end2)) {
        if(is1) {
            count1++;
            is1 = false;
        }
        return;
    } 
    if(checkFull2(arr, start1, end1, start2, end2)) {
        if(is2) {
            count2++;
            is2 = false;
        }
        return;
    }

    getCount(arr, start1, start1+size/2, start2, start2+size/2, size/2, count1, count2, is1, is2);
    getCount(arr, start1+size/2, end1, start2, start2+size/2, size/2, count1, count2, is1, is2);
    getCount(arr, start1, start1+size/2, start2+size/2, end2, size/2, count1, count2, is1, is2);
    getCount(arr, start1+size/2, end1, start2+size/2, end2, size/2, count1, count2, is1, is2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> arr(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int count1 = 0, count2 = 0;
    getCount(arr, 0, N, 0, N, N, count1, count2, true, true);

    cout << count2 << "\n";
    cout << count1 << "\n";

    return 0;
}