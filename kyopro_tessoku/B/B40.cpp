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

    // mod100で分類
    for (int i = 1; i <= N; i++)
    {
        cnt[A[i] % 100]++;
    }

    // 答えを計算
    long long ans = 0;
    for (int i = 1; i < 50; i++)
    {
        ans += cnt[i] * cnt[100 - i];
    }
    // 0,50は特別で、中から二つ選ぶ
    ans += cnt[0] * (cnt[0] - 1) / 2;
    ans += cnt[50] * (cnt[50] - 1) / 2;

    // output
    cout << ans << endl;
    return 0;
}