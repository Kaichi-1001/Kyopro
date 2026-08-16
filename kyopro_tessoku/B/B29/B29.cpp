#include <bits/stdc++.h>
using namespace std;

// bは2の何乗かを返す関数
long long binary(long long b)
{
    int c = 0;
    long long x = b;
    while (x > 0)
    {
        x /= 2;
        c++;
    }
    return c;
}

// aのb乗をmで割った余りを返す関数
long long modpow(long long a, long long b, long long m)
{
    long long p = a;
    long long ans = 1;
    for (long long i = 0; i < binary(b); i++)
    {
        long long wari = (1LL << i);
        if ((b / wari) % 2 == 1)
        {
            ans *= p;
            ans %= m;
        }
        p = (p * p) % m;
    }
    return ans;
}

int main()
{
    long long a, b;
    // 入力
    cin >> a >> b;
    // 答えを出力
    cout << modpow(a, b, 1000000007LL) << endl;
    return 0;
}