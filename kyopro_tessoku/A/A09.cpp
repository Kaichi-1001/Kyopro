#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int h,w,n;
    cin >>h>>w>>n;
    vector<vector<int>> zougen(1509,vector<int>(1509,0));
    vector<vector<int>> answer(1509,vector<int>(1509,0));
    for (int i = 0; i < n; i++)
    {
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        zougen[a][b]+=1;
        zougen[a][d+1]-=1;
        zougen[c+1][b]-=1;
        zougen[c+1][d+1]+=1;
    }
    for (int j = 1; j <= w; j++)
    {
        for (int i = 1; i <= h; i++)
        {
            zougen[i][j]=zougen[i-1][j]+zougen[i][j];
        }
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            answer[i][j]=answer[i][j-1]+zougen[i][j];
            cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout << flush;
}