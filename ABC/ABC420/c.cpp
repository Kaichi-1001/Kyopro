#include <bits/stdc++.h>
using namespace std;

int n,q,x,v;
char c;
vector<long long> a;
vector<long long> b; 

int main() {
    cin>>n>>q;
    a.resize(n+1);
    b.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin>>b[i];
    }

    long long sum=0;
    for (int i = 1; i <= n; i++)
    {
        sum+=min(a[i],b[i]);
    }

    while(q){
        q--;
        cin>>c>>x>>v;
        if(c=='A'){
            if(a[x]>=b[x]){
                if(v<=b[x]) sum=sum-b[x]+v;
                else sum=sum;
            }
            if(a[x]<b[x]){
                if(v<=b[x]) sum=sum-a[x]+v;
                else sum=sum-a[x]+b[x];
            }
            a[x]=v;
        }

        if(c=='B'){
            if(a[x]>=b[x]){
                if(v<=a[x]) sum=sum-b[x]+v;
                else sum=sum-b[x]+a[x];
            }
            if(a[x]<b[x]){
                if(v<=a[x]) sum=sum-a[x]+v;
                else sum=sum;
            }
            b[x]=v;
        }

        cout<<sum<<"\n";
    }
    cout << flush;
}