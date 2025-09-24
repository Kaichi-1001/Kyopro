#include <bits/stdc++.h>
using namespace std;

int n,mae,usiro;
vector<int> l(109,0);

int main() {
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>l[i];
    }

    for (int i = 0; i < n; i++)
    {
        if(l[i]==1){
            mae=i;
            break;
        }
    }
    
    
    for (int i = n-1; i >= 0; i--)
    {
        if(l[i]==1){
            usiro=i;
            break;
        }
    }
    
    cout<<usiro-mae<<endl;
}