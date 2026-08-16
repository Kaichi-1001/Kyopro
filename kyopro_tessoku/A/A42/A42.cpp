#include <bits/stdc++.h>
using namespace std;

int N, K, A[309], B[309];

int main()
{
    // input
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
    }

    // 2次元配列を用意して全探索で解けるはず
    vector<vector<int>> members(109, vector<int>(109, 0));
    for (int i = 1; i <= N; i++)
    {
        members[A[i]][B[i]]++;
    }

    // 2次元累積和
    vector<vector<int>> S(109, vector<int>(109, 0));
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + members[i][j];
        }
    }

    // 条件を満たす人数を計算して最大値を探索
    int ans = 0;
    for (int i = K; i <= 100; i++)
    {
        for (int j = K; j <= 100; j++)
        {
            if (i > K && j > K)
            {
                ans = max(ans, S[i][j] - S[i - K - 1][j] - S[i][j - K - 1] + S[i - K - 1][j - K - 1]);
            }
            else if (i > K)
            {
                ans = max(ans, S[i][j] - S[i - K - 1][j]);
            }
            else if (j > K)
            {
                ans = max(ans, S[i][j] - S[i][j - K - 1]);
            }
            else
            {
                ans = max(ans, S[i][j]);
            }
        }
    }

    // 答えを出力

    cout << ans << endl;
}