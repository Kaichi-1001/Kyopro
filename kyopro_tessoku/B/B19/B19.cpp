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
        for(int j=0; j<=100000; j++){
            if(j-v[i]>=0){
                if(dp[i-1][j-v[i]]>=0 && dp[i-1][j]>=0) dp[i][j] = min(dp[i-1][j-v[i]]+w[i],dp[i-1][j]);
                else if(dp[i-1][j-v[i]]>=0) dp[i][j] = dp[i-1][j-v[i]]+w[i];
                else if(dp[i-1][j]>=0) dp[i][j] = dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
     long long answer = 0;
    for (int i = 1; i <= 100000; i++)
    {
        if(dp[n][i] <= W && dp[n][i] >= 0) answer = i;
    }
    cout << answer << endl;
}