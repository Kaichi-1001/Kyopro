#include <bits/stdc++.h>
using namespace std;

int n, X[19], Y[19];
double dp[1 << 15][19]; // dp[i][j]: 整数iでまわった都市の集合を表現 jは今いる都市の番号
// 今回は移動距離を計算するから、現在位置を反映させる必要がある

int main() {
    // 入力
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i];
    }

    // dpの初期化
    for (long long i = 0; i < (1 << n); i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 2e18;
        }
    }
    dp[0][1] = 0;

    // 動的計画法
    for (long long i = 0; i < (1 << n); i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if ((i >> (k-1)) & 1) continue;

                dp[i + (1 << (k-1))][k] = min({dp[i + (1 << (k-1))][k], dp[i][j] + sqrt((X[k]-X[j])*(X[k]-X[j]) + (Y[k]-Y[j])*(Y[k]-Y[j]))}); 
            }
        }
    }

    // 出力
    cout << fixed << setprecision(5) << dp[(1 << n) - 1][1] << endl;
    return 0;
}