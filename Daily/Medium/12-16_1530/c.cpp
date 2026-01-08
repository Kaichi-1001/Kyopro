#include <bits/stdc++.h>
using namespace std;

int S, T;

int main() {
    // 入力
    cin >> S >> T;

    // 非負整数組を全探索
    int count = 0;
    for (int i = 0; i <= S; i++) {
        for (int j = 0; j <= S; j++) {
            for (int k = 0; k <= S; k++) {
                if (i + j + k <= S && i * j * k <= T) {
                    count++;
                }
            }
        } 
    }

    // 出力
    cout << count << endl;
    return 0;
}