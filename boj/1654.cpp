#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int getCount(long lan[], int K, long len) {
    int count = 0;
    for(int i = 0; i < K; i++) {
        count += lan[i]/len;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int K, N;
    cin >> K >> N;

    long lan[K];
    long low = 1;
    long mid;
    long high = 0;

    for(int i = 0; i < K; i++) {
        cin >> lan[i];
        if(high < lan[i]) {
            high = lan[i];
        }
    }

    mid = (low+high)/2;

    while(low < high) {
        if(getCount(lan, K, mid) < N) {
            high = mid;
        } else {
            if(low == mid) {
                break;
            }
            low = mid;
        }
        mid = (low+high)/2;
    }

    int result = mid;
    while(mid <= high) {
        mid++;
        if(getCount(lan, K, mid) >= N) {
            result = mid;
        }
    }

    cout << result << "\n";

    return 0;
}