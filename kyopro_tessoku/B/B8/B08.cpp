#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >>n;
    vector<vector<int>> s(1501,vector<int>(1501,0));
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >>x>>y;
        s[x][y]+=1;
    }
    vector<vector<int>> t(1501,vector<int>(1501,0));
    for (int i = 1; i <= 1500 ; i++)
    {
        for (int j = 1; j <= 1500; j++)
        {
            t[i][j]=t[i][j-1]+s[i][j];
        }
        
    }
    vector<vector<int>> u(1501,vector<int>(1501,0));
    for (int j = 1; j <= 1500; j++)
    {
        for (int i = 1; i <= 1500; i++)
        {
            u[i][j]=u[i-1][j]+t[i][j];
        }
        
    }
    int q;
    cin >>q;
    for (int i = 0; i < q; i++)
    {
        int answer=0,a,b,c,d;
        cin >>a>>b>>c>>d;
        answer=u[c][d]+u[a-1][b-1]-u[c][b-1]-u[a-1][d];
        cout<<answer<<"\n";
    }
    cout << flush;
}