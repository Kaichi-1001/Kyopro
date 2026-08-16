#include <bits/stdc++.h>
using namespace std;

int n,m,dp[2009][2009];
string s,t;

int main() {
    cin >> s; n = s.size();
    cin >> t; m = t.size();
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i>=1 && j>=1 && s[i-1]==t[j-1]) dp[i][j] = max({dp[i-1][j-1]+1, dp[i-1][j], dp[i][j-1]});
            else if(i>=1 && j>=1) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            else if(i>=1) dp[i][j] = dp[i-1][j];
            else if(j>=1) dp[i][j] = dp[i][j-1];
        }
    }
    cout << dp[n][m] << endl;
}