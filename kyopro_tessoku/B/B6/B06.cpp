#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,q,a[100009],atari[100009],hazure[100009],l[100009],r[100009];
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    cin>>q;
    for (int i = 1; i <= n; i++)
    {
        if(a[i]==1){
            atari[i]=atari[i-1]+1;
            hazure[i]=hazure[i-1];
        }
        else{
            atari[i]=atari[i-1];
            hazure[i]=hazure[i-1]+1;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin>>l[i]>>r[i];
    }
    for (int i = 0; i < q; i++)
    {
        if(atari[r[i]]-atari[l[i]-1]>hazure[r[i]]-hazure[l[i]-1])cout<<"win"<<'\n';
        else if(atari[r[i]]-atari[l[i]-1]==hazure[r[i]]-hazure[l[i]-1])cout<<"draw"<<'\n';
        else cout<<"lose"<<'\n';
    }
    cout << flush;
}