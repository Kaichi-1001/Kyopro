//到達可能な状態iをok配列で表し(1が到達可能で0が到達不可能)、その2^n-1番目が1のとき、"Yes"を出力する
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int t,n;
string s;

void test() {
    cin >> n;
    cin >> s;
    s = "0" + s;
    vector<int> ok(1<<n,0);
    ok[0]=1;
    for (int i = 0; i < 1<<n; i++)
    {
        if(ok[i]==0)continue;
        for (int j = 0; j < n; j++)
        {
            if(i&(1<<j))continue; //k番目の薬品が使われているかという情報はiの2進数表記の中に含まれており、bit演算により評価できる
            int next = i + (1<<j);
            if(s[next]=='0')ok[next]=1;
        }
        
    }
    if(ok[(1<<n)-1]==1)cout<<"Yes\n";
    else cout<<"No\n";
}

int main() {
    cin>>t;
    while(t>0){
        t--;
        test();
    }
}