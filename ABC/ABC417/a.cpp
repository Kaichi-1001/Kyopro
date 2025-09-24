#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int n,a,b;
string s;

int main() {
    cin>>n>>a>>b;
    cin>>s;
    string answer="";
    for (int i = a; i < n-b; i++)
    {
        answer.push_back(s[i]);
    }
    cout<<answer<<endl;
}