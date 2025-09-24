#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int n,a[109],x;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> x;
    
    bool answer=false;

    for (int i = 0; i < n; i++)
    {
        if (a[i]==x)
        {
            answer=true;
        }
        
    }
    if (answer==true)
    {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}