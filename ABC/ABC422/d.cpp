#include <bits/stdc++.h>
using namespace std;

long long a[(1<<20)+1],utusi[(1<<20)+1],n,k;

int main() {
    cin>>n>>k;
    a[1]=k;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= (1<<(i-1)); j++)
        {
            utusi[j]=a[j];
        }
        for (long long j = 1; j <= (1<<(i-1)); j++)
        {
            a[2*j-1]=utusi[j]/2;
            if(utusi[j]-utusi[j]/2-utusi[j]/2>0) a[2*j]=utusi[j]/2+1;
            else a[2*j]=utusi[j]/2;
        }
    }
    cout<<a[(1<<n)]-a[1]<<"\n";
    for (long long i = 1; i <= (1<<n); i++)
    {
        cout<<a[i]<<" ";
    }
    cout << flush;
}