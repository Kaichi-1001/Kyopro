#include <bits/stdc++.h>
using namespace std;

int n,a[100009],b[100009],dp[100009];
vector<int> answer;

int main() {
    cin>>n;
    for (int i = 2; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 3; i <= n; i++)
    {
        cin>>b[i];
    }
    dp[2]=a[2];
    if(n>2){
        long long tonari;
        long long tobasi;
        for (int i = 3; i <= n; i++)
        {
            tonari=dp[i-1]+a[i];
            tobasi=dp[i-2]+b[i];
            dp[i]=min(tonari,tobasi);
        }
    }
    int place = n;
    while(n){
        answer.push_back(place);
        if(place==1) break;

        if(dp[place-1]==dp[place]-a[place]) place-=1;
        else place-=2;
    }
    reverse(answer.begin(),answer.end());

    cout<<answer.size()<<"\n";

    for (int x: answer)
    {
        cout<<x<<" ";
    }
    cout << flush;
}