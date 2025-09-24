#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for (ll i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    vector<ll> count(400009,0);
    ll answer=0;
    for (ll i = 1; i <= n; i++)
    {
        if(i-a[i]>=1) answer+=count[i-a[i]];
        count[i+a[i]]++;
    }
    cout<<answer<<endl;
}