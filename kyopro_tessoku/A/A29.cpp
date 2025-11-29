#include <bits/stdc++.h>
using namespace std;

// aのb乗をmで割った余りを返す関数(繰り返し二乗法を活用)
long long modpow(long long a, long long b, long long m){
    long long p = a;
    long long ans = 1;
    for (int i = 0; i < 30; i++)
    {
        int wari = (1<<i);
        if((b/wari)%2==1){
            ans *= p;
            ans %= m;
        }
        p = (p * p) % m;
    }
    return ans;
}

int main() {
    long long a, b;
    // 入力
    cin >> a >> b;
    // 答えを出力
    cout << modpow(a, b, 1000000007LL) << endl;
    return 0;
}