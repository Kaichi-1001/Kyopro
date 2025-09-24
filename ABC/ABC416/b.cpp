#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    string s,t;
    cin>>s;
    t=s;
    int n=s.size();
    if(s[0]=='.')t[0]='o';
    for (int i = 1; i < n; i++)
    {
        if(t[i-1]=='#' && t[i]!='#')t[i]='o';
    }
    cout<<t<<endl;
}
