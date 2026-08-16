#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t,n;
    cin >>t>>n;
    vector<int> zougen(500009,0);
    for (int i = 0; i < n; i++)
    {
        int L,R;
        cin >>L>>R;
        zougen[L]+=1;
        zougen[R]-=1;
    }
    vector<int> ninzuu(500009,0);
    ninzuu[0]=zougen[0];
    for (int i = 1; i < t; i++)
    {
        ninzuu[i]=ninzuu[i-1]+zougen[i];
    }
    for (int i = 0; i < t; i++)
    {
        cout<<ninzuu[i]<<'\n';
    }
    
    cout << flush;
    
}