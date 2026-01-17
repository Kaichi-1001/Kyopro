// X=2, Y=3のとき、各山について、残りの石の個数がkのとき、kのmod5によって山のGrundy数が周期的に決まることを利用する

#include <bits/stdc++.h>
using namespace std;

long long N, X, Y, A[100009];
int A_grundy[100009];

int main() {
    // 入力
    cin >> N >> X >> Y;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // 山iのGrundy数を計算
    for (int i = 1; i <= N; i++) {
        switch (A[i] % 5) {
            case 0:
            case 1:
                A_grundy[i] = 0;
                break;
            
            case 2:
            case 3:
                A_grundy[i] = 1;
                break;
            
            case 4:
                A_grundy[i] = 2;
                break;
        }
    }

    // すべての山の排他的論理和を計算する
    int XOR_sum = 0;
    for (int i = 1; i <= N; i++) {
        XOR_sum ^= A_grundy[i];
    }

    // 出力
    if (XOR_sum == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
    return 0;
}