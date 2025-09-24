#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int n,a[109],b[109];
int main() {
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(b[i]>a[i])count+=1;
        else continue;
    }
    cout<<count<<endl;
}