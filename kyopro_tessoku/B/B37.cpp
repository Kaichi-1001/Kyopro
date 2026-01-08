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

// 1からaまでの和を返す関数
long long SUM(int a)
{
    long long res = 0;
    if (a > 0) {
        for (int i = 1; i <= a; i++)
        {
            res += i;
        }
        return res;
    }
    return 0;
}

int main()
{
    // 入力
    cin >> n;

    // nのm桁目が何回0~9を周回しているかで足していく
    long long sum = 0;
    for (int i = 1; i <= 15; i++)
    {
        // 周回の回数は、上の桁の数で決まる
        sum += (n / pow_10(i)) * 45 * pow_10(i - 1);
        
        // 周回から溢れた数は、下の桁の数で決まる
        long long r = (n / pow_10(i - 1)) % 10;
        sum += SUM(r-1) * pow_10(i - 1);

        long long s = n - (n / pow_10(i-1) * pow_10(i-1));
        sum += r * (s + 1);
    }

    // 出力
    cout << sum << endl;
    return 0;
}