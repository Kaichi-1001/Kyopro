#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,k;
    cin >> n >> k;
    int answer=0;
    for (int r = 1; r <= n; r++)
    {
        for (int b = 1; b <= n; b++)
        {
            int w=k-r-b;
            if( w >= 1 && w <= n )answer+=1;
        }
        
    }
    cout << answer << endl;
}