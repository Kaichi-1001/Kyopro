#include <bits/stdc++.h>
using namespace std;

long long A, B, x, y;

int main()
{
    // 入力
    cin >> A >> B;

    if (A < B)
    {
        x = B;
        y = A;
    }
    else
    {
        x = A;
        y = B;
    }

    // まず最大公約数を求める
    while (y != 0)
    {
        x = x % y;
        swap(x, y);
    }

    // xは最大公約数になる
    long long gcd = x;

    // 最小公倍数を計算
    long long lcm = (A * B) / gcd;

    // 出力
    cout << lcm << endl;
    return 0;
}