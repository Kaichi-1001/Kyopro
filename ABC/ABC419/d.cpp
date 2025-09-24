#include <bits/stdc++.h>
using namespace std;

int n,m;
double koukan[500009];
string s,t;

int main() {
    cin>>n>>m>>s>>t;
    while(m){
        m--;
        int l,r;
        cin>>l>>r;
        koukan[l]++;
        koukan[r+1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        koukan[i]=koukan[i]+koukan[i-1];
    }
    for (int i = 1; i <=n; i++)
    {
        koukan[i]=koukan[i]/2.0-int(koukan[i])/2;
    }
    for (int i = 1; i <= n; i++)
    {
        if(koukan[i]>0) s[i-1]=t[i-1];
    }
    cout<<s<<endl;
}