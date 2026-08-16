#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool answer=false;
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if(a[i]+a[j]+a[k]==1000)answer=true;
            }
            
        }
        
    }
    if(answer==true)cout << "Yes" << endl;
    else cout << "No" << endl;
    
}