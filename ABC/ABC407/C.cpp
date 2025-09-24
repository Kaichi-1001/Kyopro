#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    string s;
    cin >> s;
    vector<int> t={};
    for(ll i=0;i<s.size();i++){
        t.push_back(s[i]-'0');
    }
    ll count = t.size()+t[t.size()-1];
    for(ll i=1;i<t.size();i++){
        if(t[i-1]>t[i]){
            count+=t[i-1]-t[i];
        } else if(t[i-1]==t[i]){
            count+=0;
        } else if(t[i-1]<t[i]){
            count+=10+t[i-1]-t[i];
        }
    }
    cout << count << endl; 
}