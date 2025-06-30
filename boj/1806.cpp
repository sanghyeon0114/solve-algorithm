#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, S;
    cin >> N >> S;

    vector<int> arr(N, 0);
    vector<int> sum(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(i == 0) {
            sum[i] = arr[i];
        } else {
            sum[i] = arr[i] + sum[i-1];
        }
    }

    int minDistance = 0;

    // 중요 : 누적합에서 -sum[0]를 포함하지 않는 나머지 부분도 체크하기
    for(int i = 0; i < N; i++) {
        if(sum[i] >= S) {
            minDistance = i+1;
            break;
        }
    } 

    int right = 0;
    for(int left = 0; left < N; left++) {
        while(sum[right]-sum[left] < S) {
            if(right == N-1) {
                break;
            }
            right++;
        }
        if(sum[right]-sum[left] >= S && (minDistance > right-left || minDistance == 0)) {
            minDistance = right-left;
        }
    }
    cout << minDistance << "\n";
    
    return 0;
}
