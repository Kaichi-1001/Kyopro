#include <bits/stdc++.h>
using namespace std;

int n, dp[1009][1009];
string s;

int main() {
    cin >> n >> s;
    // どこかの文字を一文字選ぶと必ず長さ一の回文になるから、それを広げていく感じ
    // 動的計画法の初期化
    for(int i = 1; i <= n; i++) {
        dp[i][i] = 1; //長さ1の回文
        if(s[i-1] == s[i]) dp[i][i+1] = 2; //隣り合う２文字くらいは簡単に調べられる
        else dp[i][i+1] = 1;
    }

    if(n <= 2) {
        cout << dp[1][n] << endl;
    }

    // 動的計画法
    else {
        for(int len = 2; len <= n-1; len++) { //lenはr-lの値（s中の参照する長さ）<- この問題では長さを増やしていく処理順序にすることが大切
            for(int l = 1; l <= n-len; l++) {
                int r = l + len;
                if(s[l-1] == s[r-1]) dp[l][r] = max({dp[l+1][r-1] + 2, dp[l+1][r], dp[l][r-1]});
                // ここでdp[l+1][r-1]を参照できるのは初期化でdp[i][i+1]を設定しているから
                else dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            }
        }
        cout << dp[1][n] << endl;
    }
}