#include <bits/stdc++.h>
using namespace std;

int N, Q;
long long x[200009];

int main() {
    // 入力
    cin >> N >> Q;
    int a[N+1];
    a[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= Q; i++) {
        cin >> x[i];
    }

    // aをソートする
    sort(a + 1, a + N + 1);
    
    // 各クエリに回答
    int answer[Q+1];
    for (int i = 1; i <= Q; i++) {
        int shortest = lower_bound(a + 1, a + N + 1, x[i]) - a;
        answer[i] = N - shortest + 1;
    }

    // 答えを出力
    for (int i = 1; i <= Q; i++) {
        cout << answer[i] << "\n";
    }
    cout << flush;
    return 0;
}