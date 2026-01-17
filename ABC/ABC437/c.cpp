#include <bits/stdc++.h>
using namespace std;

long long T, N, W[300009], P[300009], WP[300009];

int main()
{
    // input
    cin >> T;

    // 各クエリに回答
    vector<long long> answer = {};
    while (T)
    {
        T--;
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> W[i] >> P[i];
            WP[i] = W[i] + P[i];
        }

        // ソート
        sort(WP + 1, WP + N + 1);

        // Pの総和を計算
        long long sum_P = 0;
        for (int i = 1; i <= N; i++)
        {
            sum_P += P[i];
        }

        // WPの累積和を計算
        for (int i = 1; i <= N; i++)
        {
            WP[i] += WP[i - 1];
        }

        // 乗れるトナカイの最大値
        long long ans = 0;
        ans = upper_bound(WP + 1, WP + N + 1, sum_P) - WP - 1;
        answer.push_back(ans);
    }

    // output
    for (long long x : answer)
    {
        cout << x << endl;
    }

    return 0;
}