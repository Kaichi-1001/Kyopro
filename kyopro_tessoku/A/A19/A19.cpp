#include <bits/stdc++.h>
using namespace std;

int n;
long long W,w[109],v[109];
vector<vector<long long>> dp(109,vector<long long>(100009,-1'000'000'000'000'000LL));

int main() {
    cin >> n >> W;
    for(int i=1; i<=n; i++) cin >> w[i] >> v[i];
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=W; j++){
            if(j-w[i]>=0) dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    long long answer = 0;
    for(int j=0; j<=W; j++) answer = max(answer,dp[n][j]);
    cout << answer << endl;
}