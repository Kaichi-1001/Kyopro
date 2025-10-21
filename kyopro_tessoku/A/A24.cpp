#include <bits/stdc++.h>
using namespace std;

int n, A[100009], dp[100009];
vector<int> L = {0};
// L[i]は長さがiの増加部分列の最後の要素の最小値、dp[i]は最後の要素がA[i]である増加部分列の長さの最大値
// 今回はLが必ず単調増加列になることから二分探索を用いて計算量を減らせる

int main() {
    // 入力
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    //　動的計画法
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(L.begin(), L.end(), A[i]) - L.begin();
        dp[i] = pos;

        // Lの更新
        int m = L.size();
        if (pos == m) {
            L.push_back(A[i]);
            // 最長増加部分列が伸びるとき
        } else {
            L[pos] = A[i];
            // Lの途中が変更になるのはよりちいさい末尾が見つかったときのみ、というか今必ずL[pos] <= A[i]のはず
        }
    }

    // 答えの導出
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, dp[i]);
    }
    
    // 出力
    cout << answer << endl;
    return 0;
}