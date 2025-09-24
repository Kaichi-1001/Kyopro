#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a;
vector<string> s;

int main() {
    cin>>n>>m;
    a.resize(n+1);
    s.resize(n+1);
    for (int i = 1; i <= n ; i++)
    {
        cin>>s[i];
    }
if(n>=3){
    int count=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(s[j][i]=='0') count++;
        }
        if(count==0 || count==n){
            for (int j = 1; j <= n; j++)
            {
                a[j]++;
            }
            
        }
        else if(count<=n/2){
            for (int j = 1; j <= n; j++)
            {
                if(s[j][i]=='0') a[j]++;
            }
        }
        else if(count>n/2){
            for (int j = 1; j <= n; j++)
            {
                if(s[j][i]=='1') a[j]++;
            }
        }
        count=0;   
    }
    int saidai=0;
    for (int i = 1; i <= n; i++)
    {
        if(a[i]>saidai) saidai=a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if(a[i]==saidai) cout<<i<<" ";
    }
    cout << endl;
}
else if(n==1) cout<<1<<endl;
}