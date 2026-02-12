#include <bits/stdc++.h>
using namespace std;

int D, N, L[10009], R[10009], H[10009], hours[366];

int main()
{
    // input
    cin >> D >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> L[i] >> R[i] >> H[i];
    }

    // initialization
    for (int i = 1; i <= 365; i++)
    {
        hours[i] = 24;
    }

    // 最大値を更新していく
    for (int i = 1; i <= N; i++)
    {
        for (int j = L[i]; j <= R[i]; j++)
        {
            hours[j] = min(H[i], hours[j]);
        }
    }
    // 最後に合計を計算して出力
    long long ans = 0;
    for (int i = 1; i <= D; i++)
    {
        ans += hours[i];
    }
    cout << ans << endl;
    return 0;
}