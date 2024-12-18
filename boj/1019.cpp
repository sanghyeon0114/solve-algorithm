#include <iostream>
#include <cmath>

using namespace std;

int not_nine[10][2];

int main() {
    // 1 -> [0, 0, 0, 0, 0, 0, 0, 0, 0, 0] + [0, 1, 0, 0, 0, 0, 0, 0, 0, 0]
    // 2 -> [0, 0, 0, 0, 0, 0, 0, 0, 0, 0] + [0, 0, 1, 0, 0, 0, 0, 0, 0, 0]
    // ...
    // 9 -> [0 + 0*9, 1(10*0+1), 1, 1, 1, 1, 1, 1, 1, 1]
    // 10 ~ 19 -> [1,1,1,1,1,1,1,1,1,1] + [0, 10, 0, 0, 0, 0, 0, 0, 0, 0]
    // 10 ~ 19 -> [1,1,1,1,1,1,1,1,1,1] + [0, 0, 10, 0, 0, 0, 0, 0, 0, 0]
    // ...
    // 99 -> [0 + 1*9, 20(10*1+10), 20, 20, 20, 20, 20, 20, 20, 20]
    // 100 ~ 199 -> [20, 20, 20, 20, 20, 20, 20, 20, 20, 20] + [0, 100, 0, 0, 0, 0, 0, 0, 0, 0]
    //           -> -> [20, 120, 20, 20, 20, 20, 20, 20, 20, 20]
    // 200 ~ 299 -> [20, 20, 120, 20, 20, 20, 20, 20, 20, 20]

    // 199 -> [29 140 40 40 ... ]
    // 299 -> [49 160 160 60 60 60 ...]

    // 999 -> [9 + 20*9, 300(10*20+100), (10*20+100), (10*20+100), (10*20+100), (10*20+100), (10*20+100), (10*20+100), (10*20+100), (10*20+100)]

    // 1999 -> 999의 개수 + 1000~ 1999의 개수
    // 2999 -> 999의 개수 + 1000~ 1999의 개수 + 2000~ 2999의 개수
    // 2543 -> 999의 개수 + 1000~ 1999의 개수 + 2000~2543의 개수( 2000~2499 + 2500~2539 + 2540~2543 )

    // 9999 -> [9 + 20*9 + 300*9, (10*300+1000), (10*300+1000), (10*300+1000), (10*300+1000), (10*300+1000), (10*300+1000), (10*300+1000), (10*300+1000), (10*300+1000)]

    
    // 999999999

    long nine[10][10];
    
    for(int j = 0; j < 10; j++) { 
        nine[0][j] = 0;
    }

    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            nine[i][j] = nine[i-1][j]*10 + (long)pow(10, i-1);
        }
        nine[i][0] += nine[i-1][0] + nine[i-1][1] * 9;
    }

    // for(int i = 0; i < 10; i++) {
    //     cout << "[";
    //     for(int j = 0; j < 10; j++) {
    //         cout << nine[i][j] << ",";
    //     }
    //     cout << "]" << endl;
    // }

    // not_nine 계산
    for(int i = 0; i < 10; i++) {
        not_nine[i][0] = nine[i][1];
        not_nine[i][1] = pow(10, i-1);
        //cout << i << " : " << not_nine[i][0] << ", " << not_nine[i][1] << endl;
    }
    
    long num, save;
    cin >> num;
    save = num;
    int size = 0;

    int number[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while(num != 0) {
        size++;
        number[size] = num%10;
        num /= 10;
    }

    int result[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < 10; i++) {
        result[i] += nine[size-1][i];
    }
    for(int headNum = 1; headNum < number[size]; headNum++) {
        result[headNum] += not_nine[size][1];
        for(int i = 0; i < 10; i++) {
            result[i] += not_nine[size-1][0];
        }
    }
    result[number[size]] += (save % (long)pow(10, size-1)) + 1;

    for(int s = size-1; s >= 0; s--) {
        for(int headNum = 0; headNum < number[s]; headNum++) {
            result[headNum] += not_nine[s][1];
            for(int i = 0; i < 10; i++) {
                result[i] += not_nine[s-1][0];
            }
        }
        // cout << "[";
        // for(int i = 0; i < 10; i++) {
        //     cout << result[i] << " ";
        // }
        // cout << "]" << endl;
        if(s != 0) {
            result[number[s]] += (save % (long)pow(10, s-1)) + 1;
        }
    }

    for(int i = 0; i < 10; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}                                                              