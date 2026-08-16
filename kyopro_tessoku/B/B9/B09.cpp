#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,zougen[1509][1509],answer[1509][1509],a[1000009],b[1000009],c[1000009],d[1000009];
int main() {
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        zougen[a[i]+1][b[i]+1]+=1;
        zougen[a[i]+1][d[i]+1]-=1;
        zougen[c[i]+1][b[i]+1]-=1;
        zougen[c[i]+1][d[i]+1]+=1;
    }
    for (int j = 1; j < 1509; j++)
    {
        for (int i = 1; i < 1509; i++)
        {
            answer[i][j]=answer[i-1][j]+zougen[i][j];
        }
    }
    int x=0;
    for (int i = 1; i < 1509; i++)
    {
        for (int j = 1; j < 1509; j++)
        {
            answer[i][j]=answer[i][j-1]+answer[i][j];
            if(answer[i][j]>=1)x+=1;
            else x+=0;
        }
    }
    cout<<x<<endl;
}