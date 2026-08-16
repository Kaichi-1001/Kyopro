#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int n;
    cin>>n;
    vector<int> ninzu(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        cin>>ninzu[i];
    }
    int D;
    cin>>D;
    vector<int> P(n+1);
    vector<int> Q(n+1);
    P[0]=ninzu[0];
    Q[n]=ninzu[n];
    for (int i = 1; i < n+1; i++)
    {
        if(ninzu[i]>=P[i-1]) P[i]=ninzu[i];
        else P[i]=P[i-1];
    }
    for (int i = n-1; i >= 0; i--)
    {
        if(ninzu[i]>=Q[i+1]) Q[i]=ninzu[i];
        else Q[i]=Q[i+1];
    }
    for (int d = 1; d <= D; d++)
    {
        int l,r,answer;
        cin>>l>>r;
        if(P[l-1]>=Q[r+1]) answer=P[l-1];
        else answer=Q[r+1];
        cout<<answer<<"\n";
    }
    cout << flush;
    
    
}