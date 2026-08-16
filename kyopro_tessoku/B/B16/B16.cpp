#include <bits/stdc++.h>
using namespace std;

int n;
long long h[100009],dp[100009];

int main() {
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>h[i];
    }
    dp[2]=abs(h[2]-h[1]);
    if(n>2){
        int tonari;
        int tobasi;
        for (int i = 3; i <= n; i++)
        {
            tonari=dp[i-1]+abs(h[i]-h[i-1]);
            tobasi=dp[i-2]+abs(h[i]-h[i-2]);
            dp[i]=min(tonari,tobasi);
        }
    }
    cout<<dp[n]<<endl;
}