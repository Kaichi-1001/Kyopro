#include <bits/stdc++.h>
using namespace std;

string s;
const long long MOD = 998244353;

int main()
{
    // input
    cin >> s;
    long long n = s.size();

    // sのi文字目まで調べて、char(a, b, c)で終わる部分列の個数をa_last, b_last, c_lastとする
    long long a_last = 0, b_last = 0, c_last = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            a_last += (1 + b_last + c_last) % MOD;
            a_last %= MOD;
        }
        else if (s[i] == 'b')
        {
            b_last += (1 + a_last + c_last) % MOD;
            b_last %= MOD;
        }
        else if (s[i] == 'c')
        {
            c_last += (1 + a_last + b_last) % MOD;
            c_last %= MOD;
        }
    }

    // output
    cout << (a_last + b_last + c_last) % MOD << endl;
    return 0;
}