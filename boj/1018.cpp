#include <iostream>
#include <vector>

using namespace std;

char compare[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};

int compareSquare(const vector<vector<char>>& arr, int x, int y) {
    int count = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(arr[x+i][y+j] != compare[i][j]) {
                count++;
            }
        }
    }
    return count < 64-count ? count : 64-count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<char>> arr(N, vector<char>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int min = 64;

    for(int i = 0; i <= N-8; i++) {
        for(int j = 0; j <= M-8; j++) {
            int tmp = compareSquare(arr, i, j);
            if(min > tmp) {
                min = tmp;
            }
        }
    }
    cout << min << endl;

    return 0;
}