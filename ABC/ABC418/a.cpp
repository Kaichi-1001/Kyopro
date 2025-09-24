#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int n;
string s;

int main() {
    cin>>n>>s;
    if((s[n-1]=='a')&&(s[n-2]=='e')&&(s[n-3]=='t')){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}