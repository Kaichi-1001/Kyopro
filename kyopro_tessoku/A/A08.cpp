#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int h,w;
    cin >>h>>w;
    vector<vector<int>> a(h+1,vector<int>(w+1,0));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin>>a[i][j];
        }
    }
    vector<vector<int>> b(h+1,vector<int>(w+1,0));
    int q;
    cin >>q;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            b[i][j]=b[i][j-1]+a[i][j];
        }
        
    }
    vector<vector<int>> c(h+1,vector<int>(w+1,0));
    for (int j = 1; j <= w; j++)
    {
        for (int i = 1; i <= h; i++)
        {
            c[i][j]=c[i-1][j]+b[i][j];
        }
    }
    for (int i = 0; i < q; i++)
    {
        int answer=0;
        int x,y,z,d;
        cin >>x>>y>>z>>d;
        answer=c[z][d]+c[x-1][y-1]-c[x-1][d]-c[z][y-1];
        cout<<answer<<"\n";
    }
    cout << flush;
}