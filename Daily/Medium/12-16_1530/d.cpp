#include <bits/stdc++.h>
using namespace std;

long long X, kaijou[21];

int main()
{
    // 入力
    cin >> X;

    // 階乗の前計算
    kaijou[1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        kaijou[i] = kaijou[i - 1] * i;
    }

    // N!=Xの解を二分探索
    int N = lower_bound(kaijou + 1, kaijou + 21, X) - kaijou;

    // 答えを出力
    cout << N << endl;
    return 0;
}