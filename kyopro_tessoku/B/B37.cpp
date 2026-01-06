#include <bits/stdc++.h>
using namespace std;

long long n;

// 10のa乗を返す関数
long long pow_10(int a)
{
    long long res = 1;
    for (int i = 0; i < a; i++)
    {
        res *= 10;
    }
    return res;
}

int main()
{
    // 入力
    cin >> n;

    // nのm桁目が何回0~9を周回しているかで足していく
    long long sum = 0;
    for (int i = 1; i <= 15; i++)
    {
        sum += (n / 10) * 45 * pow_10(i - 1); // 1から9の和は45
        int r = n % 10;
        sum += r * (r + 1) / 2 * pow_10(i - 1); // 1~rの和
        n /= 10;
    }

    // 出力
    cout << sum << endl;
    return 0;
}