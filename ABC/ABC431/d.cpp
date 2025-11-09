#include <bits/stdc++.h>
using namespace std;

int N;
long long W[509], H[509], B[509], dp[509][125009];

int main()
{
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i] >> H[i] >> B[i];
    }

    // dpの初期化
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= 125000; j++)
        {
            dp[i][j] = -1e18;
        }
    }
    dp[0][0] = 0;

    // ナップザック問題を連想しながら動的計画法(頭の重さがWtotal/2を超えなければいい)
    long long Wtotal = 0;
    for (int i = 1; i <= N; i++)
    {
        Wtotal += W[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= Wtotal / 2; j++)
        {
            if (j - W[i] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j] + B[i], dp[i - 1][j - W[i]] + H[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + B[i];
            }
        }
    }

    // 出力
    long long ans = 0;
    for (int i = 0; i <= Wtotal / 2; i++)
    {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}