#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long A[1009];
long long B[1009];
long long C[1009];
long long D[1009];
long long P[1000009];
long long Q[1000009];

int main() {
    cin>>n>>k;
    for(int i=1; i <= n; i++) cin>>A[i];
    for(int i=1; i <= n; i++) cin>>B[i];
    for(int i=1; i <= n; i++) cin>>C[i];
    for(int i=1; i <= n; i++) cin>>D[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            P[(i-1)*n+j]=A[i]+B[j];
            Q[(i-1)*n+j]=C[i]+D[j];
        }
    }
    sort(Q+1,Q+n*n+1);
    bool answer=false;
    for (int i = 1; i <= n*n; i++)
    {
        long long pos1 = lower_bound(Q+1,Q+n*n+1,k-P[i])-Q;
        if(pos1<=n*n && Q[pos1]==k-P[i]){
            answer=true;
            break;
        }
    }
    if(answer==true)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}