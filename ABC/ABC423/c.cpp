#include <bits/stdc++.h>
using namespace std;

long long n,r,mae,usiro,count_op,count_cl;
vector<int> l;

int main() {
    cin>>n>>r;
    l.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>l[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(l[i]==0){
            mae=i;
            break;
        }
    }

    for (int i = n; i >= 1; i--)
    {
        if(l[i]==0){
            usiro=i;
            break;
        }
    }
    
    if(mae<=r && r<=usiro){
        for (int i = mae; i <= usiro; i++)
        {
            if(l[i]==0) count_op++;
            if(l[i]==1) count_cl++;
        }
        cout<<count_op+count_cl*2<<endl;
    }

    else if(r<mae){
        for (int i = r+1; i <= usiro; i++)
        {
            if(l[i]==0) count_op++;
            if(l[i]==1) count_cl++;
        }
        cout<<count_op+count_cl*2<<endl;
    }

    else if(usiro<r){
        for (int i = mae; i <= r; i++)
        {
            if(l[i]==0) count_op++;
            if(l[i]==1) count_cl++;
        }
        cout<<count_op+count_cl*2<<endl;
    }
}