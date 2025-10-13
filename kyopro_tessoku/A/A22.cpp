#include <bits/stdc++.h>
using namespace std;

int n, A[100009], B[100009], dp[100009]; // dp[i]はマスiに到達するときの合計スコアの最大値

int main() {
    // n, A, Bの入力
    cin >> n;
    for (int i = 1; i <= n-1; i++) cin >> A[i];
    for (int i = 1; i <= n-1; i++) cin >> B[i];

    // 動的計画法の初期化
    dp[1] = 0;
    for (int i = 2; i <= n; i++) dp[i] = -20'000'000; // ここを十分小さくしないと、得点が入らないdp[i]（通らないマス）からもあとにスコアが影響する

    // 配る遷移形式の動的計画法
    for (int i = 1; i <= n-1; i++) {
        dp[A[i]] = max(dp[A[i]], dp[i] + 100);
        dp[B[i]] = max(dp[B[i]], dp[i] + 150);
    }

    // 答えの出力
    cout << dp[n] << endl;
}