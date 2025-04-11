#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Person {
    int height;
    int weight;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;
    Person* p_arr = new Person[N];

    for(int i = 0; i < N; i++) {
        int h, w;
        cin >> h >> w;
        Person p = {h, w};
        p_arr[i] = p;
    }

    for(int i = 0; i < N; i++) {
        int order = 1;
        for(int j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            if(p_arr[i].height < p_arr[j].height && p_arr[i].weight < p_arr[j].weight) {
                order++;
            }
        }
        cout << order << " ";
    }

    delete[] p_arr;
    return 0;
}