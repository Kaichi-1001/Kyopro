#include <bits/stdc++.h>
using namespace std;

long long N, M, C;
vector<long long> A(1000009, 0), sum(1000009, 0), X(1000009, 0);

int main() {
    // 入力
    cin >> N >> M >> C;
    A.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    // Aの重複を削除したものをBとする
    vector<long long> B = A;
    B.erase(unique(B.begin(), B.end()), B.end());

    // Aの中で、B[i]である数を数えてcnt[i]で数える
    vector<long long> cnt(1000009, 0);
    long long m = B.size();
    for (int i = 1; i < m; i++) {
        int mae = upper_bound(A.begin(), A.end(), B[i-1]) - A.begin();
        int usiro = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
        cnt[i] = usiro - mae;
    }

    // cnt[i+m-1] = cnt[i]
    for (int i = 1; i < m; i++) {
        cnt[i+m-1] = cnt[i];
    }

    // sumはcntの累積和
    for (int i = 1; i <= 2*m-2; i++) {
        sum[i] = sum[i-1] + cnt[i];
    }

    // sumをソートして重複を消す
    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());

    for (int i = 0; i < m; i++) {
        long long tomaritai = sum[i] + C;
        int stop = lower_bound(sum.begin(), sum.end(), tomaritai) - sum.begin();
        X[i] = (sum[stop] - sum[i])*(stop - i);
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += X[i];
    }

    // 答えを出力
    cout << ans << endl;
    return 0;
}