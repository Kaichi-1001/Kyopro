#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int n,x=0;
    cin >>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    bool answer=true;
    while(answer==true){
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]>=x) count+=1;
        }
        if(count<x){
            cout<<(x-1)<<endl;
            break;
        }
        count=0;
        x+=1;
    }
}