#include <bits/stdc++.h>
using namespace std;

int N;
int A[100009], dp[100009];

int main()
{
    // input
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        cin >> A[i];
    }

    // 社員Nから部下の数が決まっていくので動的計画法で部下の数を確定していく
    // 配る遷移形式
    for (int i = N; i >= 1; i--)
    {
        dp[A[i]] = dp[A[i]] + dp[i] + 1; // 自分も上司の部下であるから+1
    }

    // output
    for (int i = 1; i <= N; i++)
    {
        cout << dp[i] << " ";
    }
    cout << flush;
    return 0;
}