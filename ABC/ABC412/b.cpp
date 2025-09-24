#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;


int main() {
    string s="",t="",a="";
    cin>>s>>t;
    int x=s.size(),y=t.size();
    for (int i = 1; i < x; i++)
    {
        if((s[i]>='A'&&s[i]<='Z'))a.push_back(s[i-1]);
        else continue;
    }
    int z=a.size();
    if(z>=1){
    bool answer=false;
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < y; j++)
        {
            answer=false;
            if(a[i]==t[j]){
                answer=true;
                break;
            }
        }    
        if(answer==false)break;
    }
    if(answer==true)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
}    