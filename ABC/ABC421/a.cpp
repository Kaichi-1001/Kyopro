#include <bits/stdc++.h>
using namespace std;

int n,x;
string y;
vector<string> s;

int main() {
    cin>>n;
    s.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>s[i];
    }
    cin>>x>>y;

    if(s[x]==y) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}