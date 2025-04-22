#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int count[8001] = {0,};

    int N;
    cin >> N;

    double sum = 0;
    vector<int> v;
    vector<int> max;
    int maxCount = 0;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum += num;
        v.push_back(num);
        count[num+4000]++;
        if(maxCount < count[num+4000]) {
            maxCount = count[num+4000];
            max.clear();
            max.push_back(num);
        } else if(maxCount == count[num+4000]) {
            max.push_back(num);
        }
    }

    sort(v.begin(), v.end());
    sort(max.begin(), max.end());

    cout << (int)round(sum / N) << "\n";
    cout << v[N/2] << "\n";
    if(max.size() == 1) {
        cout << max[0] << "\n";
    } else {
        cout << max[1] << "\n";
    }
    cout << v[N-1] - v[0] << "\n";

    return 0;
}