#include <bits/stdc++.h>
using namespace std;

int N, X, Y, A[100009]; // A[i]: 山iの高さ
int grundy[100009]; // 山iのGrundy数

int main() {
    // 入力
    cin >> N >> X >> Y;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // Grundy数を計算
    for (int i = 1; i <= 100000; i++) {
        bool transit[3] = {false, false, false};
        if (i >= X) {
            transit[grundy[i-X]] = true;
        }
        if (i >= Y) {
            transit[grundy[i-Y]] = true;
        }

        if (transit[0]==false) {
            grundy[i] = 0;
        }
        else if (transit[1]==false) {
            grundy[i] = 1;
        }
        else {
            grundy[i] = 2;
        }
    }

    // すべての山の排他的論理和を計算する
    int XOR_sum = 0;
    for (int i = 1; i <= N; i++) {
        XOR_sum ^= grundy[A[i]];
    }

    // 答えを出力
    if (XOR_sum == 0) {
        cout << "Second" << endl;
    }
    else {
        cout << "First" << endl;
    }
    return 0;
}