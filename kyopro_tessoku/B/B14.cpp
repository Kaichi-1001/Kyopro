#include <bits/stdc++.h>
using namespace std;

long long n,k;
vector<long long> a,zenhan,kouhan;
bool answer=false;

int main() {
    cin>>n>>k;
    a.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(a[i]==k) answer=true;
    }
    if (n>=2)
    {
        for (long long i = 0; i < (1<<n/2); i++)
        {
            long long sum=0;
            for (int j = 1; j <= n/2; j++)
            {
                int wari=(1<<(j-1));
                if((i/wari)%2==1)sum+=a[j];
            }
            zenhan.push_back(sum);
            if(sum==k) answer=true;
        }
        for (long long i = 0; i < (1<<(n-n/2)); i++)
        {
            long long sum=0;
            for (int j = 1; j <= n-n/2; j++)
            {
                int wari=(1<<(j-1));
                if((i/wari)%2==1)sum+=a[n/2+j];
            }
            kouhan.push_back(sum);
            if(sum==k) answer=true;
        }
        
        zenhan.push_back(1500000009);
        sort(zenhan.begin(),zenhan.end());

        for (long long i = 0; i < (1<<(n-n/2)); i++)
        {
            long long l=lower_bound(zenhan.begin(),zenhan.end(),k-kouhan[i])-zenhan.begin();
            if(zenhan[l]==k-kouhan[i]) answer=true;
        }
        
    }    
    if(answer==true)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}