#include <bits/stdc++.h>
using namespace std;

int n,m,l,a[509],s[509],t[509];

int main() {
    cin>>n>>m>>l;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for (int i = l; i <= n; i++)
    {
        t[i]=s[i]-s[i-l];
    }
    int count=0;
    for (int i = l; i <= n; i++)
    {
        count+=m-(t[i]+count)%m;
    }
    cout<<count<<endl;
}