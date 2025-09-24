#include <bits/stdc++.h>
using namespace std;

long long n,k,a[100009],r[100009];

int main() {
    cin>>n>>k;
    for (long long i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (long long i = 1; i <= n; i++)
    {
        if(i==1) r[i]=1;
        else r[i]=r[i-1];

        while(a[r[i]+1]-a[i]<=k && r[i]<n){
            r[i]++;
        }
    }

    long long answer=0;
    for (long long i = 1; i < n; i++)
    {
        answer+=r[i]-i;
    }
    cout<<answer<<endl;
    
}