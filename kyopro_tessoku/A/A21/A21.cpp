#include <bits/stdc++.h>
using namespace std;

int n, P[2009], A[2009], dp[2009][2009];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> P[i] >> A[i]; 

    // 動的計画法
    int score1, score2;
    for(int len = n - 2; len >= 0; len--) { // for文の書き方がいつもと違うから注意
        for(int l = 1; l <= n - len; l++) {
            int r = l + len;
            score1 = 0; score2 = 0;
            if(l <= P[l-1] && P[l-1] <= r) score1 = A[l-1];
            if(l <= P[r+1] && P[r+1] <= r) score2 = A[r+1];
            
            if(l==1) dp[l][r] = dp[l][r+1] + score2;
            else if(r==n) dp[l][r] = dp[l-1][r] + score1;
            else dp[l][r] = max(dp[l-1][r] + score1, dp[l][r+1] + score2); 
        }
    }
    int answer = 0;
    for(int i = 1; i <= n; i++) answer = max(answer, dp[i][i]);
    cout << answer << endl;
}