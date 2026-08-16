#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long n;
vector<long long> a,b,c;

int main() {
    cin>>n;

    a.push_back(0);
    b.push_back(0);
    c.resize(n+1);

    for (long long i = 1; i <= n; i++)
    {
        long long A;
        cin>>A;
        a.push_back(A);
        b.push_back(A);
    }

    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());

    for (long long i = 1; i <= n; i++)
    {
        c[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        cout<<c[i]<<" ";
    }
    cout << flush;
}