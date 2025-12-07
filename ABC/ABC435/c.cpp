#include <bits/stdc++.h>
using namespace std;

int n, A[1000009], fall[1000009]; // A[i]:座標iにあるドミノの高さ fall[i]:座標iにあるドミノが倒れるかを表現

int main() {
    // 入力
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }


    // 累積和の考えにより、ドミノが倒れる様子を表現する
    for (int i = 1; i <= n; i++) {
        fall[i]++;
        fall[i + A[i]]--;
    }
    for (int i = 1; i <= n; i++) {
        fall[i] += fall[i - 1];
    }

    int answer = n;
    for (int i = 2; i <= n; i++) {
        if (fall[i] == 1) {
            answer = i - 1;
            break;
        }
    }

    // 出力
    cout << answer << endl;
    
}