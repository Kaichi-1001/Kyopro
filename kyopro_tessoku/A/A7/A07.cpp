#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int d,n,l[100009],r[100009];
    cin >>d>>n;
    vector<int> zennjituhi(100009,0);
    for (int i = 0; i < n; i++)
    {
        cin>>l[i]>>r[i];
    }
    for (int i = 0; i < n; i++)
    {
        zennjituhi[l[i]]+=1;
        zennjituhi[r[i]+1]-=1;
    }
    int syusseki[100009];
    for (int i = 1; i <= d; i++)
    {
        syusseki[i]=syusseki[i-1]+zennjituhi[i];
        cout<<syusseki[i]<<'\n';
    }
    cout << flush;
    
    
}