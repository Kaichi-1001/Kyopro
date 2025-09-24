#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int n;
    cin >>n;
    string t,a;
    cin >>t>>a;
    bool answer=false;
    for (int i = 0; i < n; i++)
    {
        if((t[i]==a[i])&&(a[i]=='o')){
            answer=true;
            break;
        }   
    }
    if(answer==true) cout <<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    cout << flush;
}