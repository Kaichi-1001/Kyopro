#include <bits/stdc++.h>
using namespace std;

int n, m, A[109][19], dp[109][2000];
// dp[i][j]はクーポンiまでつかったときに無料になる品物の集合を整数jで表現したもの
int main() {
    // 入力
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    // dpの初期化
    for (int i = 0; i < 109; i++)
    {
        for (int j = 0; j < 2000; j++)
        {
            dp[i][j] = 1000000000LL;
        }
    }
    dp[0][0] = 0;
    
    // 動的計画法
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            // jを集合として表現（無料なのは何か）
            int already[19];
            for (int k = 1; k <= n; k++)
            {
                if (j & (1 << (k - 1))) already[k] = 1;
                else already[k] = 0;
            }

            // vによるT_i(クーポンiで無料になる集合)とjで表されたすでに無料である集合の和集合の表現
            int v = 0;
            for (int k = 1; k <= n; k++)
            {
                if (already[k] == 1 || A[i][k] == 1) v += (1 << (k - 1));
            }
            
            // dpの更新
            dp[i][j] = min(dp[i][j], dp[i-1][j]); // クーポンiを使わないとき
            dp[i][v] = min(dp[i][v], dp[i-1][j] + 1); // クーポンiを使うとき
        }
    }
    
    // 出力
    if (dp[m][(1 << n) - 1] == 1000000000LL) cout << -1 << endl;
    else cout << dp[m][(1 << n) - 1] << endl;
    return 0;
}