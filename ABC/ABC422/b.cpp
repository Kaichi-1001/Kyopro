#include <bits/stdc++.h>
using namespace std;

int h,w;
string s[22];

int main() {
    cin>>h>>w;
    s[0]="......................";
    s[h+1]="......................";
    for (int i = 1; i <= h; i++)
    {
        cin>>s[i];
        s[i]="."+s[i]+".";
    }
    bool answer=true;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            int count = 0;
            if(s[i][j]=='#'){
                if(s[i-1][j]=='#') count++;
                if(s[i+1][j]=='#') count++;
                if(s[i][j-1]=='#') count++;
                if(s[i][j+1]=='#') count++;
                if(count!=2 && count!=4) answer=false;
            }
        }
    }
    if(answer==true) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}