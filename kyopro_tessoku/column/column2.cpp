#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,k;
    cin >>n>>k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    bool answer=false;
    for (int i = 0; i < (1 << n); i++)
    {
        int sum=0;
        for (int j = 1; j <= n; j++)
        {
            int devide=1<<(j-1);
            if ((i/devide)%2==1)
            {
                sum+=a[j];
            }
            
        }
        if (sum==k)
        {
            answer=true;
        }
        
        
    }
    if (answer==true)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    
    
}