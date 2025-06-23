#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <unordered_map>

using namespace std;

void bt(vector<int> &num, int num_end, int current_position, int end_position, vector<string> &arr, string num_arr, vector<int> &order_arr) {
    if(current_position == end_position) {
        arr.push_back(num_arr);
        return;
    }
    for(int i = 0; i < num_end; i++) {
        bool isBreak = false;
        for(int j = 0; j < current_position; j++) {
            if(order_arr[j] == i) {
                isBreak = true;
                break;
            }
        }
        if(isBreak) {
            continue;
        }
        string num_arr2 = num_arr;
        num_arr2.append(to_string(num[i]));
        num_arr2.append(" ");
        order_arr[current_position] = i;
        bt(num, num_end, current_position+1, end_position, arr, num_arr2, order_arr);
    }
}

int main() {

    int M, N;
    cin >> M >> N;

    vector<int> num(M, 0);
    vector<string> arr;

    for(int i = 0; i < num.size(); i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    for(int i = 0; i < num.size(); i++) {
        string num_arr;
        num_arr.append(to_string(num[i]));
        num_arr.append(" ");
        vector<int> order_arr(N, 0);
        order_arr[0] = i;
        bt(num, M, 1, N, arr, num_arr, order_arr);
    }

    unordered_map<string, bool> map;

    for(string order : arr) {
        map[order] = true;
    }

    for(string order : arr) {
        if(map[order]) {
            map[order] = false;
            cout << order << "\n";
        }
    }

    return 0;
}