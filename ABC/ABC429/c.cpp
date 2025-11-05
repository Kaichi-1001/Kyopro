#include <bits/stdc++.h>
using namespace std;

long long n, A[200009], cnt[200009];

int main() {
    // 入力
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // Aに何回整数mが出現するかをcntに保存
    for (int i = 1; i <= n; i++) {
        cnt[A[i]]++;
    }

    // 条件を満たす整数組の数を求める
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] >= 2) {
            long long k = cnt[i];
            ans += (k * (k-1) / 2) * (n - k);
        }
    }

    // 答えを出力
    cout << ans << endl;
    return 0;
}