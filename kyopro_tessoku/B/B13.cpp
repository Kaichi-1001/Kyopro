#include <bits/stdc++.h>
using namespace std;

long long n,k,a[100009],s[100009],r[100009];

long long sum(int L,int R){
    return s[R]-s[L-1];
}

int main() {
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        s[i]=s[i-1]+a[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(i==1) r[i]=0;
        else r[i]=r[i-1];

        while(sum(i,r[i]+1)<=k && r[i]<n){
            r[i]++;
        }
    }

    long long answer=0;
    for (int i = 1; i <= n; i++)
    {
        answer+=r[i]-i+1;
    }
    cout<<answer<<endl;
    
}