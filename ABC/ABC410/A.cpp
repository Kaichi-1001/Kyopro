#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int n,k;
    cin >>n;
    vector<int> a(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cin>>k;
    int count=0;
    for(int x : a){
        if (k<=x)
        {
            count+=1;
        }
        
    }
    cout<<count<<endl;
}