#include <bits/stdc++.h>
using namespace std;

int N;
long long A[200009], cnt[109];

int main()
{
    // input
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    // 個数を前計算
    for (int i = 1; i <= N; i++)
    {
        cnt[A[i]]++;
    }

    // 答えを計算
    long long ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (cnt[i] > 2)
        {
            long long k = cnt[i];
            long long tasu = k * (k - 1) * (k - 2) / 6;
            ans += tasu;
        }
    }

    // output
    cout << ans << endl;
    return 0;
}