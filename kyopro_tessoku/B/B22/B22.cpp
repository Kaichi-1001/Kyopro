// A16を配る遷移形式で解く

#include <bits/stdc++.h>
using namespace std;

long long n, A[100009], B[100009], dp[100009];

int main()
{
    // 入力
    cin >> n;
    for (int i = 2; i <= n; i++)
        cin >> A[i];
    for (int i = 3; i <= n; i++)
        cin >> B[i];

    // 初期化
    for (int i = 2; i < 100009; i++)
    {
        dp[i] = 1000000000000000000LL; // 10^18
    } // 今回はdpのi番目をminで決定するから初期値は最大値をにしておく
    

    // 配る遷移形式の動的計画法
    for (int i = 1; i <= n - 2; i++)
    {
        dp[i + 1] = min({dp[i + 1], dp[i] + A[i + 1]});
        dp[i + 2] = min({dp[i + 2], dp[i] + B[i + 2]});
    }
    dp[n] = min({dp[n], dp[n - 1] + A[n]});

    // 出力
    cout << dp[n] << endl;
}