#include <bits/stdc++.h>
using namespace std;

long long t,answer[200009];

int main() {
    cin>>t;
    for(long long i=1;i<=t;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        long long small=min(a,c);
        if((a+b+c)>=3*small) answer[i]=small;
        else answer[i]=(a+b+c)/3;
    }
    for (long long i = 1; i <= t; i++)
    {
        cout<<answer[i]<<"\n";
    }
    cout << flush;
    
}