#include <bits/stdc++.h>
using namespace std;

string s;
long long dp[300009];

int main()
{
    // input
    cin >> s;
    int n = s.size();

    // sのi文字目で終わるsの部分文字列で、条件を満たすものの個数をdp[i]とする
    dp[0] = 1;
    if (n > 1)
    {
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = dp[i - 1] + 1;
            }
        }
    }

    // 答えを計算
    long long answer = 0;
    long long wari = 998244353LL;
    for (int i = 0; i < n; i++)
    {
        answer += dp[i] % wari;
        answer %= wari;
    }
    cout << answer << endl;
    return 0;
}