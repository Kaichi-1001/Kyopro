#include <bits/stdc++.h>
using namespace std;

int N, K, a[109], dp[200009];

int main() {
    // 入力
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        cin >> a[i];
    }

    // 配る遷移形式の動的計画法
    for (int i = 0; i<N; i++) {
        for (int j = 1; j<=K; j++) {
            if (dp[i] == 0){
                dp[i+a[j]] = 1;
            }
        }
    }
    
    // 出力
    if (dp[N] == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}