// 終了時刻が早い映画を選び続けると、必ずそのあとに見れる映画の数が最大になることを利用する
#include <bits/stdc++.h>
using namespace std;

int N, L[300009], R[300009];
vector<pair<int, int>> tmp; // 映画をソートするための一時変数
int main()
{
    // input
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> L[i] >> R[i];
        tmp.push_back(make_pair(R[i], L[i]));
    }

    // 映画をソート
    sort(tmp.begin(), tmp.end());
    for (int i = 1; i <= N; i++)
    {
        R[i] = tmp[i - 1].first;
        L[i] = tmp[i - 1].second;
    }

    // 開始が現在時刻より遅く、終了時刻が最も早いものを貪欲に選び続ける
    int ans = 0;
    int current_time = 0;
    for (int i = 1; i <= N; i++)
    {
        if (L[i] >= current_time)
        {
            ans++;
            current_time = R[i];
        }
    }

    // output
    cout << ans << endl;
    return 0;
}