#include <bits/stdc++.h>
using namespace std;

int N, A[2009];
int dp[2009][2009];

int main()
{
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    // 初期化
    for (int i = 1; i <= N; i++)
    {
        dp[N][i] = A[i];
    }
    // 動的計画法でゴールからさかのぼる感じで処理する
    // iが奇数の時は先手（最大化したい）、iが偶数の時は後手（最小化したい）
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % 2 == 1)
            {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
    }

    // 結果を出力
    cout << dp[1][1] << endl;
    return 0;
}