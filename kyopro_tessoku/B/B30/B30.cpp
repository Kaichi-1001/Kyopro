#include <bits/stdc++.h>
using namespace std;

long long H, W;

// aの階乗をmで割った余りを求める関数
long long modpow(long long a, long long m) {
    long long ans = 1;
    for (long long i = 1; i <= a; i++)
    {
        ans = (ans * i) % m;
    }
    return ans;
}

// aのb乗をmで割った余りを返す関数
long long power(long long a, long long b, long long m) {
    long long p = a;
    long long ans = 1;
    for (long long i = 0; i < 60; i++)
    {
        long long hantei = (1LL << i);
        if (b & hantei)
        {
            ans = (ans * p) % m;
        }
        p = (p * p) % m;
    }
    return ans;
}

// a/bをmで割った余りを求める関数
long long moddiv(long long a, long long b, long long m) {
    return (a * power(b, m-2, m)) % m;
}

int main() {
    // 入力
    cin >> H >> W;

    long long m = 1e9 + 7;

    // 階乗の計算
    long long a = modpow(H+W-2, m);
    long long b = (modpow(H-1, m) * modpow(W-1, m)) % m;

    // 答えを出力
    cout << moddiv(a, b, m) << endl;
}