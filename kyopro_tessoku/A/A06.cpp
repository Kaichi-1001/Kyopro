#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,q;
    cin >>n>>q;
    int a[n];
    if(n!=1){   
       for (int i = 0; i < n; i++)
       {
           cin>>a[i];
       }
       int b[n];
       for (int i = 1; i < n; i++)
       {
           b[i]=b[i-1]+a[i];  
       }
       int l[q],r[q];
       for (int i = 0; i < q; i++)
       {
           cin>>l[i]>>r[i];
       }
       for (int i = 0; i < q; i++)
       {
           cout<<b[r[i]-1]-b[l[i]-1]+a[l[i]-1]<<"\n";
       }
       cout << flush;
       
    }
    else {
        cin>>a[0];
        for (int i = 0; i < q; i++)
        {
            cout<<a[0]<<"\n";
        }
        cout << flush;
    }
    
}