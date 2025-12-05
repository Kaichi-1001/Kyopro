#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int nokori[100009]; // 残りi個で必勝の時、nokori[i]=1,負けのときnokori[i]=0

int main() {
    // 入力
    cin >> n >> a >> b;

    // 初期化
    nokori[a] = 1;
    nokori[b] = 1;

    // 動的計画法的にnokoriを計算
    for (int i = 1; i <= n; i++) {
        if (i >= b) {
            if (nokori[i-b] == 0 || nokori[i-a] == 0){
                nokori[i] = 1;
            }
        }
        else if (i >= a) {
            if (nokori[i-a] == 0){
                nokori[i] = 1;
            }
        }
    }

    // 答えの出力
    if (nokori[n] == 1) {
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }
}