#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double l=0,r=100;
    cin>>n;
    while(r-l>0.001){
        double mid=(l+r)/2;
        double ans = mid*mid*mid + mid;
        if(ans>n) r=mid;
        if(ans<=n) l=mid;
    }
    cout<<fixed<<setprecision(5)<<l<<endl;
}