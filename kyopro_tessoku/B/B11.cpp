#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,q;
vector<ll> a;

int main() {
    cin>>n;
    a.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    a.push_back(1000000009);
    cin>>q;
    while(q){
        q--;
        ll x;
        cin>>x;
        ll ans=lower_bound(a.begin(),a.end(),x)-a.begin();
        cout<<ans<<"\n";
    }
    cout << flush;
}