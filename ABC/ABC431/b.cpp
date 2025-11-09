#include <bits/stdc++.h>
using namespace std;

int X, N, W[109], Q, P[109], parts[109];

int main()
{
    // 　入力
    cin >> X >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i];
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> P[i];
    }

    // クエリに回答
    long long weight = X;
    for (int i = 1; i <= Q; i++)
    {
        if (parts[P[i]] & 1)
        {
            parts[P[i]] = 0;
            weight -= W[P[i]];
            cout << weight << "\n";
        }
        else
        {
            parts[P[i]] = 1;
            weight += W[P[i]];
            cout << weight << "\n";
        }
    }

    cout << flush;
    return 0;
}