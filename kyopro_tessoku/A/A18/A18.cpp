#include <bits/stdc++.h>
using namespace std;

int n,s;
int a[10009],dp[61][10009];

int main() {
    cin >> n >> s;
    for(int i=1; i<=n; i++) cin >> a[i];
    dp[0][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=s; j++){
            if(dp[i-1][j]==1){
                dp[i][j] = 1;
                if(j+a[i]<=s) dp[i][j+a[i]] = 1;
            }
        }
    }
    if(dp[n][s]==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}