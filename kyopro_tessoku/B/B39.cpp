#include <bits/stdc++.h>
using namespace std;

long long N, D, X[200009], Y[200009];
vector<pair<long long, long long>> tmp; // 仕事をソートするための一時配列
int main()
{
    // input
    cin >> N >> D;
    for (int i = 1; i <= N; i++)
    {
        cin >> X[i] >> Y[i];
        tmp.push_back(make_pair(Y[i], X[i]));
    }

    // 仕事を報酬で逆順ソート
    sort(tmp.rbegin(), tmp.rend());
    for (int i = 1; i <= N; i++)
    {
        Y[i] = tmp[i - 1].first;
        X[i] = tmp[i - 1].second;
    }
    // 仕事を貪欲に選び続ける
    long long ans = 0;
    vector<bool> check(200009, false); // 仕事iを選んだかをチェックする配列
    for (int current = 0; current <= D; current++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (!check[i] && X[i] <= current)
            {
                ans += Y[i];
                check[i] = true;
                break;
            }
        }
    }

    // output
    cout << ans << endl;
    return 0;
}