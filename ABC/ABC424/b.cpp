#include <bits/stdc++.h>
using namespace std;

int n,m,k,seikai[11];


int main() {
    cin >> n >> m >> k;
    while(k){
        k--;
        int a,b;
        cin >> a >> b;
        seikai[a]++;
        if(seikai[a] == m) cout << a << " ";
    }
    cout << flush;
}