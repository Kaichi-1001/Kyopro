#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int n,l,r;
string s;

int main() {
    cin>>n>>l>>r>>s;
    bool answer=true;
    for (int i = l-1; i < r; i++)
    {
        if(s[i]=='x')answer=false;
    }
    if(answer==true)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
}