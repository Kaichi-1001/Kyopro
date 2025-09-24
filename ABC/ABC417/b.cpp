#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    
    vector<int> answer={};

    for (int i = 0; i < n; i++)
    {
        bool sonzai=false;
        for (int j = 0; j < m; j++)
        {
            if(a[i]==b[j]){
                sonzai=true;
                b[j]=0;
                break;
            }
        }
        if(sonzai==false)answer.push_back(a[i]);
    }
    int l=answer.size();
    for (int i = 0; i < l; i++)
    {
        cout<<answer[i]<<' ';
    }
    cout << flush;
    
}