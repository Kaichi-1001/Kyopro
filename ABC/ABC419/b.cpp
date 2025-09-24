#include <bits/stdc++.h>
using namespace std;

int q,fukuro[109];

int main() {
    cin>>q;
    while(q){
        q--;
        int l,r;
        cin>>l;
        if(l==1){
            cin>>r;
            fukuro[r]++;
        }
        if(l==2){
            for (int i = 1; i <= 100; i++)
            {
                if(fukuro[i]>0){
                    cout<<i<<"\n";
                    fukuro[i]--;
                    break;
                }
            }
        }
    }
}