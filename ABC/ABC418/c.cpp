#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

ll n,q,sum[1000009],cnt[1000009];
vector<ll> a;

int main() {
    cin>>n>>q;
    a.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
        sum[a[i]]+=a[i];
        cnt[a[i]]++;
    }

    for (ll i = 1; i < 1000009; i++)
    {
        sum[i]=sum[i]+sum[i-1];
        cnt[i]=cnt[i]+cnt[i-1];
    }
    while(q){
        q--;
        ll b;
        cin>>b;
        if(cnt[b-1]==n) cout<<-1<<"\n";
        else cout<<sum[b-1]+(b-1)*(n-cnt[b-1])+1<<"\n";
    }
    cout << flush;
}
// 1からiまでの和を考えるときは累積和を導入
// ある値以下の配列因子の個数を数えたかったら、数直線と累積和をイメージ
// 配列の中で評価するよりも数直線上にプロットして累積和で数える方が、各クエリで評価せずに済む