#include <bits/stdc++.h>
using namespace std;

int N;
long long R[200009],L[200009];

int main() {
    cin>>N;
    for (int i = 1; i <= N; i++)
    {
        cin>>R[i]>>L[i];
    }
    sort(R+1,R+N+1);
    sort(L+1,L+N+1);

    long long r,l;
    if(double(R[N]-R[1])/2-(R[N]-R[1])/2>0) r=(R[N]-R[1])/2+1;
    if(double(R[N]-R[1])/2-(R[N]-R[1])/2==0) r=(R[N]-R[1])/2;
    if(double(L[N]-L[1])/2-(L[N]-L[1])/2>0) l=(L[N]-L[1])/2+1;
    if(double(L[N]-L[1])/2-(L[N]-L[1])/2==0) l=(L[N]-L[1])/2;

    if(l<=r)cout<<r<<endl;
    if(l>r)cout<<l<<endl;
}