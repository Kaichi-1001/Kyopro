#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long A[300009], B[300009], B_sum[300009];
long long wari = 998244353LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    // Bをソートして累積和を取る
    sort(B, B + m);
    for (int i = 0; i < m; i++) {
        B_sum[i + 1] = (B_sum[i] + B[i]) % wari;
    }

    long long total_ans = 0;

    for (int i = 0; i < n; i++) {
        // Bの中で A[i] がどの位置に来るか二分探索
        int k = lower_bound(B, B + m, A[i]) - B;

        // B_j <= A[i] の部分: (A[i] * k - sum(B_0...B_{k-1}))
        long long low_part = (A[i] * k) % wari;
        low_part = (low_part - B_sum[k] + wari) % wari;

        // B_j > A[i] の部分: (sum(B_k...B_{m-1}) - A[i] * (m - k))
        long long high_sum = (B_sum[m] - B_sum[k] + wari) % wari;
        long long high_part = (high_sum - (A[i] * (m - k) % wari) + wari) % wari;

        total_ans = (total_ans + low_part + high_part) % wari;
    }

    cout << total_ans << endl;

    return 0;
}